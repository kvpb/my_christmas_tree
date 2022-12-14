/*//	Copyright 2022 Karl Vincent Pierre Bertin
////
////	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
////
////	1.	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
////
////	2.	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
////
////	3.	Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
////
*///	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/*
**
** QWASAR.IO -- my_christmas_tree
**
** @param {} 
**
** @return {}
**
*/

#include <stdlib.h> // STRTOL
#include <math.h> // POW, Floor
#include <unistd.h> // Write
//#include <stdio.h> // PRINTF	debug

/*struct dimensions_tree
{
	int number_scale;
	int width_maximum;
	int height_maximum;
};*/

//void sky_draw( int width_maximum, int width_tree );

void crown_draw( int number_argument, int width_maximum/*, int height_maximum*/ )
{
	int number_scale, number_backup;
	int width, width_offset, width_offset_backup, width_difference;
	int height;
	//int l_index, d/*istance*/_offset;
	int k_index, j_index, i_index;

	number_scale/*size*/ = number_argument;
	number_backup = number_scale;
	width = 1;
	width_difference = 2;
	height = 4;

	width_offset = 0;
	width_offset_backup = width_offset;
	k_index = 0;
	while ( k_index < number_argument )
	{
		width_offset_backup = width_offset;
		j_index = 0;
		while ( j_index < height )
		{
			i_index = 0;
			while ( i_index < width_maximum / 2 - width / 2 + ( width_offset % 2 ) * 1 ) // Jesus Christ. Figuring this out took me two months. I kept mixing up this expression and that of the maximum width.
			{
				write( 1, " ", 1 );
				i_index++;
			}
			i_index = 0;
			while ( i_index < width )
			{
				write( 1, "*", 1 );
				i_index++;
			}
			write( 1, "\n", 1 );
			width += 2; // -----------,
			width_offset_backup++; // |
			j_index++; //             |
		} //                          |
		width -= 2; // <--------------'
		height += 1;

		width = width - width_difference;
		width_offset += width_difference;
		number_scale += 1;
		if ( ( 3 < number_argument ) && ( number_backup == number_scale - 2 ) )
		{
			width_difference += 2;
			number_backup = number_scale;
		}

		k_index++;
	}
}

void trunk_draw( int number_argument, int width_maximum )
{
	int i_index;
	int j_index;

	j_index = 0;
	while ( j_index < number_argument )
	{
		i_index = 0;
		while ( i_index < width_maximum / 2 - number_argument / 2 + ( 1 - number_argument % 2 ) * 1 )
		{
			write( 1, " ", 1 );
			i_index++;
		}
		i_index = 0;
		while ( i_index < number_argument )
		{
			write( 1, "|", 1 );
			i_index++;
		}
		write( 1, "\n", 1 );
		j_index++;
	}
}

int main( int count_argument, char* vector_argument[] ) // As usual read my variable, function or routine names backwards, e.g. 'argument vector' for `vector_argument`.
{
	if ( count_argument != 2 )
		return 1;

	int number_argument;
	int width_maximum;
	//int height_maximum;

	number_argument = (int) strtol( vector_argument[ 1 ], (char**) NULL, 10 );
	//if ( 0 < number_argument )
	//	height_maximum = ( number_argument * 4 ) /* treetop */ + ( ( ( number_argument - 1 ) * ( ( number_argument - 1 ) + 1 ) ) / 2 ) /* crown */ + number_argument /* trunk */; // Karl V. P. B.'s h.
	//else
	//	height_maximum = 1;
	if ( 0 < number_argument )
		width_maximum = ( 2 * ( 3 * number_argument ) + 2 * ( number_argument / 2 ) * ( ( number_argument / 2 ) - ( ( number_argument + 1 ) % 2 ) ) ) + ( 1 ); // Ian Beauregard's w. // I almost had it! He obviously forwent the height in the calculation of the width. Why did I not do that all along? That will teach me. I refactored it at least. When I did, I also realized I had started going for the full width, whereas Ian went for the half width. I ended up confusing this expression (of the maximum width) with that of the working width, and figuring out that of the working width took me two months. How do I know that for sure, if I was tired? Although I have discarded my last draft, I remember I was backcalculating n from h_max with d in w for some reason. And my former prototype for crown_draw and the leftover one of sky_draw also do seem to attest this. But since my variable height_maximum shows I started to do it the other way round, this alone already attests it. TL;DR: I screwed up.
	else
		width_maximum = 0;
	crown_draw( number_argument, width_maximum/*, height_maximum*/ );
	trunk_draw( number_argument, width_maximum );

	return 0;
}

/*//	my_christmas_tree.c
////	My Christmas Tree
////
////	Karl V. P. B. `kvpb` AKA Karl Thomas George West `ktgw`
////	+1 (DDD) DDD-DDDD
////	+33 A BB BB BB BB
////	local-part@domain
////	bertin_k@qwasar.io
////	https://github.com/kvpb
////	https://upskill.us.qwasar.io/users/bertin_k
////
////	Stop,
////	stop
////	fantasy!
////	Live together.
////		You can see
////	It's the best
////		how you fall away.
*///	way of life.
