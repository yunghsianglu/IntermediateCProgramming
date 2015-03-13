// encode.h
#ifndef ENCODE_H
#define ENCODE_H
// encode the input (text) file
// save the result in the output (binary) file
// return 0 if cannot read from file or write to file
// return 1 if success
int encode(char * infile, char * outfile);
// decode the input (binary) file
// save the result in the output (text) file
// return 0 if cannot read from file or write to file
// return 1 if success
int decode(char * infile, char * outfile);
#endif
