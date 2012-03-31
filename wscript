VERSION = '0.1.0'
APPNAME = 'libsvmutil'

def options(opt):
  opt.load('compiler_cxx')
  opt.load('unittest_gtest')

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
  conf.load('compiler_cxx')
  conf.load('unittest_gtest')

def build(bld):
  bld.program(
    features = 'gtest',
    source = 'libsvmutil_test.cpp',
    target = 'test',
  )
