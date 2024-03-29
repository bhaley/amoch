// ============================================================================
// triple.cc -- AMOCH::Triple methods
// ----------------------------------------------------------------------------
// Copyright (c) 2019 Benjamin P. Haley
// ----------------------------------------------------------------------------
// See the LICENSE file for information on usage and redistribution of this
// file and for a DISCLAIMER OF ALL WARRANTIES.
// ============================================================================

#include "triple.h"

using AMOCH::Real;
using AMOCH::Triple;

// ============================================================================
// Constructor
// ============================================================================
Triple::Triple(Real xx,
               Real yy,
               Real zz) :
   x(xx),
   y(yy),
   z(zz)
{}

// ============================================================================
// Add-assign
// ============================================================================
Triple& 
Triple::operator+=(const Triple& rhs)
{
   x += rhs.x;
   y += rhs.y;
   z += rhs.z;
   return *this;
}

// ============================================================================
// Subtract-assign
// ============================================================================
Triple& 
Triple::operator-=(const Triple& rhs)
{
   x -= rhs.x;
   y -= rhs.y;
   z -= rhs.z;
   return *this;
}

// ============================================================================
// Scale-assign
// ============================================================================
Triple& 
Triple::operator*=(Real f)
{
   x *= f;
   y *= f;
   z *= f;
   return *this;
}
   
// ============================================================================
// Return lhs + rhs
// ============================================================================
Triple 
operator+(const Triple& lhs,
          const Triple& rhs)
{
   Triple ret(lhs);

   return ret += rhs;
}

// ============================================================================
// Return lhs - rhs
// ============================================================================
Triple 
operator-(const Triple& lhs,
          const Triple& rhs)
{
   Triple ret(lhs);

   return ret -= rhs;
}

// ============================================================================
// Return lhs * f 
// ============================================================================
Triple 
operator*(const Triple& lhs,
          Real f)
{
   Triple ret(lhs);

   return ret *= f;
}

// ============================================================================
// Return the dot (inner) product lhs * rhs
// ============================================================================
Real 
dot(const Triple& lhs,
    const Triple& rhs)
{
   return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

// ============================================================================
// Return the cross (vector) product lhs x rhs
// ============================================================================
Triple
cross(const Triple& lhs,
      const Triple& rhs)
{
   Triple ret;

   ret.x = lhs.y*rhs.z - lhs.z*rhs.y;
   ret.y = lhs.z*rhs.x - lhs.x*rhs.z;
   ret.z = lhs.x*rhs.y - lhs.y*rhs.x;
   return ret;
}

