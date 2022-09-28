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

#include <unistd.h> // Write
#include <math.h> // POW, Floor
#include <stdlib.h> // STRTOL
#include <stdio.h> // PRINTF // debug

/*struct dimensions_tree
{
	int number_argument;
	int width_maximum;
	int height_maximum;
};*/

//void sky_draw( int width_maximum, int width_tree );

void crown_draw( int number_argument, int width_maximum, int height_maximum )
{
	int number;
	int number_backup;
	int width_max;
	int width;
	int width_minus;
	int height_max;
	int height;
	int index;
	int index_offset;
	int i;
	int j;
	int k;

	number = number_argument;
	number_backup = number;
	width_max = width_maximum;
	width = 1;
	width_minus = 2;
	height_max = height_maximum;
	height = 4;
	index = 0;
	index_offset = 0;
	k = 0;
	while ( k < number_argument )
	{
		index = index_offset;
		j = 0;
		while ( j < height )
		{
			i = 0;
			while ( i < width_max / 2 - width / 2 + ( index_offset % 2 ) * 1 ) // Jesus fucking Christ. This line literally took me two months.
			{
				write( 1, " ", 1 );
				i++;
			}
			i = 0;
			while ( i < width )
			{
				write( 1, "*", 1 );
				i++;
			}
			write( 1, "\n", 1 );
			width += 2; // -,
			index++; //     |
			j++; //         |
		} //                |
		width -= 2; // <----'
		height += 1;

		width = width - width_minus;
		index_offset += width_minus; // It still fails. The moment I decided to tinker with an offset, I felt like I was going into a dead end.
		number += 1;
		if ( ( 3 < number_argument ) && ( number_backup == number - 2 ) )
		{
			width_minus += 2;
			number_backup = number; //+= 2;
		}

		k++;
	}
} // doesn't work. Gotta rewrite that part from scratch.

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

int main( int count_argument, char* vector_argument[] )
{
	if ( count_argument != 2 )
		return 1;

	int number_argument;
	int width_maximum;
	int height_maximum;

	number_argument = (int) strtol( vector_argument[ 1 ], (char**) NULL, 10 );
	if ( 0 < number_argument )
		height_maximum = ( number_argument * 4 ) /* treetop */ + ( ( ( number_argument - 1 ) * ( ( number_argument - 1 ) + 1 ) ) / 2 ) /* crown */ + number_argument /* trunk */; // yes yes YES GOT IT HELL YEAH I OWN YOU MOTHERFUCKER // Karl V. P. B.'s h.
	else
		height_maximum = 1;
	if ( 0 < number_argument )
		width_maximum = ( 2 * ( 3 * number_argument ) + 2 * ( number_argument / 2 ) * ( ( number_argument / 2 ) - ( ( number_argument + 1 ) % 2 ) ) ) + ( 1 ); // Ian Beauregard's w. // Ian obviously forwent the height in the calculation of the width. Why did I not do that all along? I should have! Christ. That will teach me. I refactored it at least.
	else
		width_maximum = 0;

	crown_draw( number_argument, width_maximum, height_maximum );
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