from distutils.core import setup, Extension

module1 = Extension('CFuncEntry',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0'),
                                     ('Py_DEBUG', 1)],
                    include_dirs = ['/usr/local/include'],
                    library_dirs = ['/usr/local/lib'],
                    sources = ['testlib.cpp'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a demo package',
       author = 'Martin v. Loewis',
       author_email = 'martin@v.loewis.de',
       url = 'https://docs.python.org/extending/building',
       long_description = '''
This is really just a demo package.
''',
       ext_modules = [module1])
