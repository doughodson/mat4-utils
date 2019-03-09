//-------------------------------------------------------
// This code was lifted from Octave source renamed, and modified
// to a more modern syntax
//
// Copyright (C) 1996-2019 John W. Eaton
//
// This file is part of Octave.
//
// Octave is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Octave is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//-------------------------------------------------------

#ifndef __swap_bytes_HPP__
#define __swap_bytes_HPP__

static inline void swap_bytes(void* ptr, unsigned int i, unsigned int j)
{
  char* t{static_cast<char*> (ptr)};

  char tmp{t[i]};
  t[i] = t[j];
  t[j] = tmp;
}

template <int n>
void swap_bytes(void* ptr)
{
   for (int i{}; i < n/2; i++) {
      swap_bytes (ptr, i, n-1-i);
   }
}

template <>
inline void swap_bytes<1>(void*)
{ }

template <>
inline void swap_bytes<2>(void* ptr)
{
   swap_bytes (ptr, 0, 1);
}

template <>
inline void swap_bytes<4>(void* ptr)
{
   swap_bytes(ptr, 0, 3);
   swap_bytes(ptr, 1, 2);
}

template <>
inline void swap_bytes<8>(void* ptr)
{
   swap_bytes(ptr, 0, 7);
   swap_bytes(ptr, 1, 6);
   swap_bytes(ptr, 2, 5);
   swap_bytes(ptr, 3, 4);
}

template <int n>
void swap_bytes(void* ptr, int len)
{
   char* t{static_cast<char*> (ptr)};

   for (int i{}; i < len; i++) {
      swap_bytes<n>(t);
      t += n;
   }
}

template <>
inline void swap_bytes<1>(void*, int)
{ }

#endif

