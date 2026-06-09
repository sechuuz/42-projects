import importlib


def check_dependencies() -> bool:
    print()
    print("LOADING STATUS: Loading programs...")
    print()
    success = True
    dependencies = {
        "pandas": "Data manipulation ready",
        "numpy": "Numerical computation ready",
        "matplotlib": "Visualization ready",
    }
    for package, msg in dependencies.items():
        try:
            module = importlib.import_module(package)
            print(f"[OK] {package} {module.__version__} - {msg}")
        except ImportError:
            print(f"[KO] Missing dependency: '{package}'")
            success = False
    if success:
        print()
        return True
    return False


def matrix_analysis() -> None:
    import pandas
    import numpy
    import matplotlib.pyplot as plt

    print("Analyzing Matrix Data...")
    print("Processing 1000 data points...")
    signals = numpy.random.randint(0, 5, 1000)
    danger_levels = numpy.random.rand(1000)
    df = pandas.DataFrame(
        {
            "Signals": signals,
            "Danger Levels": danger_levels
        }
    )
    print("Generating visualization...")
    plt.figure(figsize=(10, 6))
    plt.scatter(df.index, df["Danger Levels"],
                color="green", s=8, alpha=0.7)
    plt.title("Matrix Analysis")
    plt.ylabel("Danger Level")
    plt.xlabel("Signal Index")
    plt.savefig("matrix_analysis.png")
    plt.close()
    print()
    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")


if __name__ == "__main__":
    if check_dependencies():
        matrix_analysis()
    else:
        print()
        print("Install dependencies using pip:")
        print("  pip install -r requirements.txt")
        print()
        print("Install dependencies using Poetry:")
        print("  poetry install")
        print("  poetry run python loading.py")
