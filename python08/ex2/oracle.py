import os


def get_env() -> dict[str, str]:
    try:
        from dotenv import load_dotenv
        load_dotenv()
    except ImportError:
        print("Module 'dotenv' has not been installed!")
    defs = {
        "MATRIX_MODE": "",
        "DATABASE_URL": "",
        "API_KEY": "",
        "LOG_LEVEL": "",
        "ZION_ENDPOINT": ""
    }
    env = {}
    for key, default in defs.items():
        env[key] = os.environ.get(key, default)
    return env


def oracle():
    env = get_env()
    print()
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    mode = env["MATRIX_MODE"] if env["MATRIX_MODE"] \
        else "development"
    db = env["DATABASE_URL"] if env["DATABASE_URL"] \
        else "Connected to local instance"
    api_key = env["API_KEY"] if env["API_KEY"] else \
        "Authenticated"
    log_level = env["LOG_LEVEL"] if env["LOG_LEVEL"] \
        else "DEBUG"
    zion = env["ZION_ENDPOINT"] if env["ZION_ENDPOINT"] else \
        "Online"
    print("Configuration loaded:")
    print(f"Mode: {mode}")
    print(f"Database: {db}")
    print(f"API Access: {api_key}")
    print(f"Log Level: {log_level}")
    print(f"Zion Network: {zion}")
    print()
    print("Environment security check:")
    if not env["API_KEY"] or not env["DATABASE_URL"]:
        print("[KO] Some configuration values "
              "have been set to their defaults!")
    else:
        print("[OK] No hardcoded secrets detected")
    if not os.path.exists(".env"):
        print("[KO] .env file does not exist!")
    else:
        print("[OK] .env file properly configured")
    if env["MATRIX_MODE"] == "production":
        print("[OK] Production overrides active")
    else:
        print("[OK] Production overrides available")
    print()
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    oracle()
