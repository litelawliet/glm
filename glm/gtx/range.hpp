///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref gtx_range
/// @file glm/gtx/range.hpp
/// @date 2014-09-19 / 2014-09-19
/// @author Joshua Moerman
///
/// @brief Defines begin and end for vectors and matrices. Useful for range-based for loop.
/// The range is defined over the elements, not over columns or rows (e.g. mat4 has 16 elements).
///
///////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../gtc/type_ptr.hpp"

namespace glm{
namespace detail
{
	/* The glm types provide a .length() member, but for matrices
	 this only defines the number of columns, so we need to work around this */
	template <typename T, precision P>
	length_t number_of_elements_(tvec2<T, P> const & v){
		return v.length();
	}

	template <typename T, precision P>
	length_t number_of_elements_(tvec3<T, P> const & v){
		return v.length();
	}

	template <typename T, precision P>
	length_t number_of_elements_(tvec4<T, P> const & v){
		return v.length();
	}

	template <typename genType>
	length_t number_of_elements_(genType const & v){
		return v.length() * v[0].length();
	}

	template <typename genType>
	const typename genType::value_type * begin(const genType& v){
		return value_ptr(v);
	}

	template <typename genType>
	const typename genType::value_type * end(const genType& v){
		return begin(v) + number_of_elements_(v);
	}

	template <typename genType>
	typename genType::value_type * begin(genType& v){
		return value_ptr(v);
	}

	template <typename genType>
	typename genType::value_type * end(genType& v){
		return begin(v) + number_of_elements_(v);
	}
}
}