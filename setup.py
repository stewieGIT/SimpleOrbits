from setuptools import setup, Extension

def main():
    setup(name="sorbits",
          version="1.0.0",
          description="Python interface that allows multiple orbit calculations",
          ext_modules=[Extension("sorbits", ["simple_orbits.c"])])

if __name__ == "__main__":
    main()
