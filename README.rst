libsvmutil
==========

About
-----

This library includes simple utilily functions to read libsvm format files.


Usage
-----

::

  istringstream ifs(filename);
  for (libsvmutil::example data; libsvmutil::read_data(ifs, data); ) {
    // do something to data
  }

See 'libsvmutil_test.cpp' for more examples.


License
-------

This library is distributed under the new BSD license.