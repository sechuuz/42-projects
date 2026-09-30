#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM_CODERS 4
#define TIME_BURNOUT 800
#define TIME_COMPILE 200
#define TIME_DEBUG 200
#define TIME_REFACTOR 200
#define COMPILES_REQUIRED 3

typedef struct s_coder_test
{
    int             id;
    int             compile_count;
    long long       last_compile_start;
    pthread_mutex_t state_lock;
} t_coder_test;

pthread_mutex_t dongles[NUM_CODERS];
pthread_mutex_t print_lock;
pthread_mutex_t sim_lock;

int             simulation_running = 1;
long long       start_time = 0;
t_coder_test    coders[NUM_CODERS];

long long get_current_time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int is_sim_running(void)
{
    pthread_mutex_lock(&sim_lock);
    int run = simulation_running;
    pthread_mutex_unlock(&sim_lock);
    return run;
}

void safe_print(int id, const char *msg)
{
    pthread_mutex_lock(&print_lock);
    if (is_sim_running())
        printf("%lld %d %s\n", get_current_time_ms() - start_time, id, msg);
    pthread_mutex_unlock(&print_lock);
}

void *coder_routine(void *arg)
{
    t_coder_test *c = (t_coder_test *)arg;
    int left = c->id - 1;
    int right = c->id % NUM_CODERS;

    int first = (left < right) ? left : right;
    int second = (left < right) ? right : left;

    while (is_sim_running())
    {
        // 1. Take Dongles
        pthread_mutex_lock(&dongles[first]);
        safe_print(c->id, "has taken a dongle");

        pthread_mutex_lock(&dongles[second]);
        safe_print(c->id, "has taken a dongle");

        // 2. Start Compiling
        pthread_mutex_lock(&c->state_lock);
        c->last_compile_start = get_current_time_ms();
        pthread_mutex_unlock(&c->state_lock);

        safe_print(c->id, "is compiling");
        usleep(TIME_COMPILE * 1000);

        pthread_mutex_lock(&c->state_lock);
        c->compile_count++;
        pthread_mutex_unlock(&c->state_lock);

        // 3. Put Dongles Down
        pthread_mutex_unlock(&dongles[second]);
        pthread_mutex_unlock(&dongles[first]);

        // 4. Debug & Refactor
        safe_print(c->id, "is debugging");
        usleep(TIME_DEBUG * 1000);

        safe_print(c->id, "is refactoring");
        usleep(TIME_REFACTOR * 1000);
    }
    return NULL;
}

void *monitor_routine(void *arg)
{
    (void)arg;
    while (is_sim_running())
    {
        int all_done = 1;
        long long now = get_current_time_ms();

        for (int i = 0; i < NUM_CODERS; i++)
        {
            pthread_mutex_lock(&coders[i].state_lock);

            // Check Burnout
            if (now - coders[i].last_compile_start > TIME_BURNOUT)
            {
                pthread_mutex_lock(&print_lock);
                printf("%lld %d burned out\n", now - start_time, coders[i].id);
                pthread_mutex_lock(&sim_lock);
                simulation_running = 0;
                pthread_mutex_unlock(&sim_lock);
                pthread_mutex_unlock(&print_lock);
                pthread_mutex_unlock(&coders[i].state_lock);
                return NULL;
            }

            // Check Compiles Required
            if (coders[i].compile_count < COMPILES_REQUIRED)
                all_done = 0;

            pthread_mutex_unlock(&coders[i].state_lock);
        }

        if (all_done)
        {
            pthread_mutex_lock(&sim_lock);
            simulation_running = 0;
            pthread_mutex_unlock(&sim_lock);
            return NULL;
        }

        usleep(1000); // Check every 1 ms
    }
    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_CODERS];
    pthread_t monitor;

    pthread_mutex_init(&print_lock, NULL);
    pthread_mutex_init(&sim_lock, NULL);
    start_time = get_current_time_ms();

    for (int i = 0; i < NUM_CODERS; i++)
    {
        coders[i].id = i + 1;
        coders[i].compile_count = 0;
        coders[i].last_compile_start = start_time;
        pthread_mutex_init(&coders[i].state_lock, NULL);
        pthread_mutex_init(&dongles[i], NULL);
    }

    pthread_create(&monitor, NULL, monitor_routine, NULL);
    for (int i = 0; i < NUM_CODERS; i++)
        pthread_create(&threads[i], NULL, coder_routine, &coders[i]);

    pthread_join(monitor, NULL);
    for (int i = 0; i < NUM_CODERS; i++)
        pthread_join(threads[i], NULL);

    for (int i = 0; i < NUM_CODERS; i++)
    {
        pthread_mutex_destroy(&dongles[i]);
        pthread_mutex_destroy(&coders[i].state_lock);
    }
    pthread_mutex_destroy(&print_lock);
    pthread_mutex_destroy(&sim_lock);

    printf("Simulation cleanly finished!\n");
    return 0;
}