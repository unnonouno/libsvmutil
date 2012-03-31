/*
Copyright (c) 2012, Yuya Unno
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Yuya Unno nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBSVMUTIL_HPP_
#define LIBSVMUTIL_HPP_

#include <string>
#include <istream>
#include <vector>

namespace libsvmutil {

struct example {
  std::string label;
  std::vector<std::pair<int, float> > feature_vector;
};

inline
bool read_data(
    std::istream& in,
    example& data) {
  std::string line;
  if (!std::getline(in, line))
    return false;
  std::istringstream is(line);

  std::string l;
  std::vector<std::pair<int, float> > d;
  is >> l;
  while (true) {
    int feature;
    float value;
    char colon;
    is >> feature >> colon >> value;
    if (!is)
      break;
    d.push_back(std::make_pair(feature, value));
  }

  l.swap(data.label);
  d.swap(data.feature_vector);
  return true;
}

inline
void read_all(
    std::istream& in,
    std::vector<example>& data) {
  std::vector<example> d;
  for (example e; read_data(in, e); ) {
    d.push_back(e);
  }
  d.swap(data);
}

}

#endif // LIBSVMUTIL_HPP_
