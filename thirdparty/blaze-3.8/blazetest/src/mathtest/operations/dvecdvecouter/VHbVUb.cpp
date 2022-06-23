//=================================================================================================
/*!
//  \file src/mathtest/operations/dvecdvecouter/VHbVUb.cpp
//  \brief Source file for the VHbVUb dense vector/dense vector outer product math test
//
//  Copyright (C) 2012-2020 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/HybridVector.h>
#include <blaze/math/UniformVector.h>
#include <blazetest/mathtest/Creator.h>
#include <blazetest/mathtest/operations/dvecdvecouter/OperationTest.h>
#include <blazetest/system/MathTest.h>

#ifdef BLAZE_USE_HPX_THREADS
#  include <hpx/hpx_main.hpp>
#endif


//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running 'VHbVUb'..." << std::endl;

   using blazetest::mathtest::TypeB;

   try
   {
      // Vector type definitions
      using VHb = blaze::HybridVector<TypeB,128UL>;
      using VUb = blaze::UniformVector<TypeB>;

      // Creator type definitions
      using CVHb = blazetest::Creator<VHb>;
      using CVUb = blazetest::Creator<VUb>;

      // Running tests with small vectors
      for( size_t i=0UL; i<=6UL; ++i ) {
         for( size_t j=0UL; j<=6UL; ++j ) {
            RUN_DVECDVECOUTER_OPERATION_TEST( CVHb( i ), CVUb( j ) );
         }
      }

      // Running tests with large vectors
      RUN_DVECDVECOUTER_OPERATION_TEST( CVHb(  67UL ), CVUb(  67UL ) );
      RUN_DVECDVECOUTER_OPERATION_TEST( CVHb(  67UL ), CVUb( 127UL ) );
      RUN_DVECDVECOUTER_OPERATION_TEST( CVHb( 127UL ), CVUb(  67UL ) );
      RUN_DVECDVECOUTER_OPERATION_TEST( CVHb( 127UL ), CVUb( 127UL ) );
      RUN_DVECDVECOUTER_OPERATION_TEST( CVHb(  64UL ), CVUb(  64UL ) );
      RUN_DVECDVECOUTER_OPERATION_TEST( CVHb(  64UL ), CVUb( 128UL ) );
      RUN_DVECDVECOUTER_OPERATION_TEST( CVHb( 128UL ), CVUb(  64UL ) );
      RUN_DVECDVECOUTER_OPERATION_TEST( CVHb( 128UL ), CVUb( 128UL ) );
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during dense vector/dense vector outer product:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
