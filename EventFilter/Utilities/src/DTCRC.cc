#include "EventFilter/Utilities/interface/DTCRC.h"

void dt_crc::calcCRC(long word, int& myC) 
{
  
  int myCRC[16], D[64], C[16];
  
  for ( int i = 0; i < 64; ++i ) { D[i]    = (word >> i) & 0x1; }
  for ( int i = 0; i < 16; ++i ) { C[i]    = (myC>>i)  & 0x1; }

  myCRC[0] = ( D[63] + D[62] + D[61] + D[60] + D[55] + D[54] +
	       D[53] + D[52] + D[51] + D[50] + D[49] + D[48] +
	       D[47] + D[46] + D[45] + D[43] + D[41] + D[40] +
	       D[39] + D[38] + D[37] + D[36] + D[35] + D[34] +
	       D[33] + D[32] + D[31] + D[30] + D[27] + D[26] +
	       D[25] + D[24] + D[23] + D[22] + D[21] + D[20] +
	       D[19] + D[18] + D[17] + D[16] + D[15] + D[13] +
	       D[12] + D[11] + D[10] + D[9]  + D[8]  + D[7]  +
	       D[6]  + D[5]  + D[4]  + D[3]  + D[2]  + D[1]  +
	       D[0]  + C[0]  + C[1]  + C[2]  + C[3]  + C[4]  +
	       C[5]  + C[6]  + C[7]  + C[12] + C[13] + C[14] +
	       C[15] )%2;

  myCRC[1] = ( D[63] + D[62] + D[61] + D[56] + D[55] + D[54] +
	       D[53] + D[52] + D[51] + D[50] + D[49] + D[48] +
	       D[47] + D[46] + D[44] + D[42] + D[41] + D[40] +
	       D[39] + D[38] + D[37] + D[36] + D[35] + D[34] +
	       D[33] + D[32] + D[31] + D[28] + D[27] + D[26] +
	       D[25] + D[24] + D[23] + D[22] + D[21] + D[20] +
	       D[19] + D[18] + D[17] + D[16] + D[14] + D[13] +
	       D[12] + D[11] + D[10] + D[9]  + D[8]  + D[7]  +
	       D[6]  + D[5]  + D[4]  + D[3]  + D[2]  + D[1]  +
	       C[0]  + C[1]  + C[2]  + C[3]  + C[4]  + C[5]  +
	       C[6]  + C[7]  + C[8]  + C[13] + C[14] + C[15] )%2;

  myCRC[2] = ( D[61] + D[60] + D[57] + D[56] + D[46] + D[42] +
	       D[31] + D[30] + D[29] + D[28] + D[16] + D[14] +
	       D[1]  + D[0]  + C[8]  + C[9]  + C[12] + C[13] )%2;

  myCRC[3] = ( D[62] + D[61] + D[58] + D[57] + D[47] + D[43] +
	       D[32] + D[31] + D[30] + D[29] + D[17] + D[15] +
	       D[2]  + D[1]  + C[9]  + C[10] + C[13] + C[14] )%2;

  myCRC[4] = ( D[63] + D[62] + D[59] + D[58] + D[48] + D[44] +
	       D[33] + D[32] + D[31] + D[30] + D[18] + D[16] + 
	       D[3]  + D[2]  + C[0]  + C[10] + C[11] + C[14] +
	       C[15] )%2;

  myCRC[5] = ( D[63] + D[60] + D[59] + D[49] + D[45] + D[34] +
	       D[33] + D[32] + D[31] + D[19] + D[17] + D[4]  +
	       D[3]  + C[1]  + C[11] + C[12] + C[15] )%2;

  myCRC[6] = ( D[61] + D[60] + D[50] + D[46] + D[35] + D[34] +
	       D[33] + D[32] + D[20] + D[18] + D[5]  + D[4]  +
	       C[2]  + C[12] + C[13] )%2;

  myCRC[7] = ( D[62] + D[61] + D[51] + D[47] + D[36] + D[35] +
	       D[34] + D[33] + D[21] + D[19] + D[6]  + D[5]  +
	       C[3]  + C[13] + C[14] )%2;

  myCRC[8] = ( D[63] + D[62] + D[52] + D[48] + D[37] + D[36] +
	       D[35] + D[34] + D[22] + D[20] + D[7]  + D[6]  +
	       C[0]  + C[4]  + C[14] + C[15] )%2;

  myCRC[9] = ( D[63] + D[53] + D[49] + D[38] + D[37] + D[36] +
	       D[35] + D[23] + D[21] + D[8]  + D[7]  + C[1]  +
	       C[5]  + C[15] )%2;

  myCRC[10] = ( D[54] + D[50] + D[39] + D[38] + D[37] + D[36] + 
		D[24] + D[22] + D[9]  + D[8]  + C[2]  + C[6] )%2;

  myCRC[11] = ( D[55] + D[51] + D[40] + D[39] + D[38] + D[37] +
		D[25] + D[23] + D[10] + D[9]  + C[3]  + C[7] )%2;

  myCRC[12] = ( D[56] + D[52] + D[41] + D[40] + D[39] + D[38] +
		D[26] + D[24] + D[11] + D[10] + C[4]  + C[8] )%2;

  myCRC[13] = ( D[57] + D[53] + D[42] + D[41] + D[40] + D[39] +
		D[27] + D[25] + D[12] + D[11] + C[5]  + C[9] )%2;

  myCRC[14] = ( D[58] + D[54] + D[43] + D[42] + D[41] + D[40] +
		D[28] + D[26] + D[13] + D[12] + C[6]  + C[10] )%2;

  myCRC[15] = ( D[63] + D[62] + D[61] + D[60] + D[59] + D[54] +
		D[53] + D[52] + D[51] + D[50] + D[49] + D[48] + 
		D[47] + D[46] + D[45] + D[44] + D[42] + D[40] +
		D[39] + D[38] + D[37] + D[36] + D[35] + D[34] + 
		D[33] + D[32] + D[31] + D[30] + D[29] + D[26] +
		D[25] + D[24] + D[23] + D[22] + D[21] + D[20] + 
		D[19] + D[18] + D[17] + D[16] + D[15] + D[14] +
		D[12] + D[11] + D[10] + D[9]  + D[8]  + D[7]  + 
		D[6]  + D[5]  + D[4]  + D[3]  + D[2]  + D[1]  +
		D[0]  + C[0]  + C[1]  + C[2]  + C[3]  + C[4]  + 
		C[5]  + C[6]  + C[11] + C[12] + C[13] + C[14] +
		C[15] )%2;

  int tempC = 0x0;  
  for ( int i = 0; i < 16 ; ++i) { tempC = tempC + ( myCRC[i] << i ); }
  myC = tempC;

  return;

}

void dt_crc::calcCRC(int myD1, int myD2, int & myC) 
{

  int myCRC[16], D[64], C[16];

  for ( int i = 0; i < 32; ++i ) { D[i]    = (myD2>>i) & 0x1; }
  for ( int i = 0; i < 32; ++i ) { D[i+32] = (myD1>>i) & 0x1; }
  for ( int i = 0; i < 16; ++i ) { C[i]    = (myC>>i)  & 0x1; }

  myCRC[0] = ( D[63] + D[62] + D[61] + D[60] + D[55] + D[54] +
               D[53] + D[52] + D[51] + D[50] + D[49] + D[48] +
               D[47] + D[46] + D[45] + D[43] + D[41] + D[40] +
               D[39] + D[38] + D[37] + D[36] + D[35] + D[34] +
               D[33] + D[32] + D[31] + D[30] + D[27] + D[26] +
               D[25] + D[24] + D[23] + D[22] + D[21] + D[20] +
               D[19] + D[18] + D[17] + D[16] + D[15] + D[13] +
               D[12] + D[11] + D[10] + D[9]  + D[8]  + D[7]  +
               D[6]  + D[5]  + D[4]  + D[3]  + D[2]  + D[1]  +
               D[0]  + C[0]  + C[1]  + C[2]  + C[3]  + C[4]  +
               C[5]  + C[6]  + C[7]  + C[12] + C[13] + C[14] +
               C[15] )%2;

  myCRC[1] = ( D[63] + D[62] + D[61] + D[56] + D[55] + D[54] +
	              D[53] + D[52] + D[51] + D[50] + D[49] + D[48] +
	              D[47] + D[46] + D[44] + D[42] + D[41] + D[40] +
	              D[39] + D[38] + D[37] + D[36] + D[35] + D[34] +
	              D[33] + D[32] + D[31] + D[28] + D[27] + D[26] +
	              D[25] + D[24] + D[23] + D[22] + D[21] + D[20] +
	              D[19] + D[18] + D[17] + D[16] + D[14] + D[13] +
	              D[12] + D[11] + D[10] + D[9]  + D[8]  + D[7]  +
	              D[6]  + D[5]  + D[4]  + D[3]  + D[2]  + D[1]  +
	              C[0]  + C[1]  + C[2]  + C[3]  + C[4]  + C[5]  +
	       C[6]  + C[7]  + C[8]  + C[13] + C[14] + C[15] )%2;

  myCRC[2] = ( D[61] + D[60] + D[57] + D[56] + D[46] + D[42] +
	              D[31] + D[30] + D[29] + D[28] + D[16] + D[14] +
	       D[1]  + D[0]  + C[8]  + C[9]  + C[12] + C[13] )%2;

  myCRC[3] = ( D[62] + D[61] + D[58] + D[57] + D[47] + D[43] +
	              D[32] + D[31] + D[30] + D[29] + D[17] + D[15] +
	       D[2]  + D[1]  + C[9]  + C[10] + C[13] + C[14] )%2;

  myCRC[4] = ( D[63] + D[62] + D[59] + D[58] + D[48] + D[44] +
	              D[33] + D[32] + D[31] + D[30] + D[18] + D[16] + 
	              D[3]  + D[2]  + C[0]  + C[10] + C[11] + C[14] +
	       C[15] )%2;

  myCRC[5] = ( D[63] + D[60] + D[59] + D[49] + D[45] + D[34] +
	              D[33] + D[32] + D[31] + D[19] + D[17] + D[4]  +
	       D[3]  + C[1]  + C[11] + C[12] + C[15] )%2;

  myCRC[6] = ( D[61] + D[60] + D[50] + D[46] + D[35] + D[34] +
	              D[33] + D[32] + D[20] + D[18] + D[5]  + D[4]  +
	       C[2]  + C[12] + C[13] )%2;

  myCRC[7] = ( D[62] + D[61] + D[51] + D[47] + D[36] + D[35] +
	              D[34] + D[33] + D[21] + D[19] + D[6]  + D[5]  +
	       C[3]  + C[13] + C[14] )%2;

  myCRC[8] = ( D[63] + D[62] + D[52] + D[48] + D[37] + D[36] +
	              D[35] + D[34] + D[22] + D[20] + D[7]  + D[6]  +
	       C[0]  + C[4]  + C[14] + C[15] )%2;

  myCRC[9] = ( D[63] + D[53] + D[49] + D[38] + D[37] + D[36] +
	              D[35] + D[23] + D[21] + D[8]  + D[7]  + C[1]  +
	       C[5]  + C[15] )%2;

  myCRC[10] = ( D[54] + D[50] + D[39] + D[38] + D[37] + D[36] + 
		D[24] + D[22] + D[9]  + D[8]  + C[2]  + C[6] )%2;

  myCRC[11] = ( D[55] + D[51] + D[40] + D[39] + D[38] + D[37] +
		D[25] + D[23] + D[10] + D[9]  + C[3]  + C[7] )%2;

  myCRC[12] = ( D[56] + D[52] + D[41] + D[40] + D[39] + D[38] +
		D[26] + D[24] + D[11] + D[10] + C[4]  + C[8] )%2;

  myCRC[13] = ( D[57] + D[53] + D[42] + D[41] + D[40] + D[39] +
		D[27] + D[25] + D[12] + D[11] + C[5]  + C[9] )%2;

  myCRC[14] = ( D[58] + D[54] + D[43] + D[42] + D[41] + D[40] +
		D[28] + D[26] + D[13] + D[12] + C[6]  + C[10] )%2;

  myCRC[15] = ( D[63] + D[62] + D[61] + D[60] + D[59] + D[54] +
		D[53] + D[52] + D[51] + D[50] + D[49] + D[48] + 
		        D[47] + D[46] + D[45] + D[44] + D[42] + D[40] +
		D[39] + D[38] + D[37] + D[36] + D[35] + D[34] + 
		D[33] + D[32] + D[31] + D[30] + D[29] + D[26] +
		D[25] + D[24] + D[23] + D[22] + D[21] + D[20] + 
		D[19] + D[18] + D[17] + D[16] + D[15] + D[14] +
		D[12] + D[11] + D[10] + D[9]  + D[8]  + D[7]  + 
		D[6]  + D[5]  + D[4]  + D[3]  + D[2]  + D[1]  +
		D[0]  + C[0]  + C[1]  + C[2]  + C[3]  + C[4]  + 
		        C[5]  + C[6]  + C[11] + C[12] + C[13] + C[14] +
		C[15] )%2;

  int tempC = 0x0;  
  for ( int i = 0; i < 16 ; ++i) { tempC = tempC + ( myCRC[i] << i ); }
  myC = tempC;
  return;
}

