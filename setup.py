from setuptools import setup, Extension

def main():
    setup(name="sorbits",
          version="0.0.2",
          description="Python interface that allows multiple orbit calculations",
          ext_modules=[Extension(
              "sorbits", 
              sources=[
                  "src/module.c",
                  "src/vector.c",
                  "src/orbit.c"
              ],
              include_dirs=["include"]
              )
          ])

if __name__ == "__main__":
    main()
