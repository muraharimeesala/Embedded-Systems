#include<stdio.h>
int set_bit(int x,int n){
	return x|(1<<n);
}
int clear_bit(int x,int n){
	return x&~(1<<n);
}
int toggle_bit(int x,int n){
	return x^(1<<n);
}
int check_bit(int x,int n){
	return (x>>n)&1;
}
int set_firstNbits(int x,int n){
        return x|(1<<n)-1;
}
int clear_firstNbits(int x,int n){
        return x&~(1<<n)-1;
}
int toggle_firstNbits(int x,int n){
        return x^(1<<n)-1;
}
int lowest_extract(int x){
	return x&0xF;
}int highesr_extract(unsigned char x){
	return (x>>4)&0xF;
}
int extract_middle_bits(int x,int i,int j) {
    int mask=((1<<(j-i+1))-1)<<i;
    return (x&mask)>>i;
}
unsigned char pack_twoNibbles(unsigned char x,unsigned char y){
	return ((x&0xF)<<4)|(y&0xF);
}
unsigned char unpack_twoNibbles(unsigned char x,unsigned char *high,unsigned char *low){
	*high=(x>>4)&0xF;
	*low=x&0xF;
}
int extract_sign_bit(int x){
	return (x>>31)&1;
}
int is_odd(int x){
	return (x&1);
}
int is_even(int x){
	return !(x&1);
}
int turn_off_rightmost_set_bit(int x){
	return x&(x-1);
}
int get_rightmost_set_bit(int x){
	return x& -x;
}
int get_rightmost_unset_bit(int x){
	return x&(x+1);
}
unsigned int mask_even_bits(){
	return 0x55555555;
}
unsigned int mask_odd_bits(){
        return 0xAAAAAAAA;
}
int main(){
	int x,n;
	printf("Enter X value:");
	scanf("%d",&x);
	printf("Enter bit position:");
	scanf("%d",&n);
	printf("Set bit %d: %d\n", n, set_bit(x, n));
        printf("Clear bit %d: %d\n", n, clear_bit(x, n));
    	printf("Toggle bit %d: %d\n", n, toggle_bit(x, n));
	printf("Check bit %d: %d\n", n, check_bit(x, n));
    	printf("Set first %d bits: %d\n", n, set_firstNbits(x,n));
    	printf("Clear first %d bits of %d: %d\n", n, x, clear_firstNbits(x, n));
    	printf("Toggle first %d bits of %d: %d\n", n, x, toggle_firstNbits(x, n));
       	printf("Lowest nibble of %d: %d\n", x, lowest_extract(x));
	printf("Highest nibble of byte 0xAB: %d\n", highesr_extract(x));
    	printf("Extract bits 1 to 3 from %d: %d\n", x, extract_middle_bits(x,1,3));
    	unsigned char packed = pack_twoNibbles(0xA, 0x5);
    	printf("Packed 0xA and 0x5 into byte: 0x%X\n", packed);
       	unsigned char high, low;
  	unpack_twoNibbles(packed, &high, &low);
     	printf("Unpacked -> High: %X, Low: %X\n", high, low);
 	printf("Sign bit of %d: %d\n", x, extract_sign_bit(x));
	printf("%d is odd? %d\n", x, is_odd(x));    
    	printf("%d is even? %d\n", x, is_even(x));
    	printf("Turn OFF rightmost set bit of %d: %d\n", x, turn_off_rightmost_set_bit(x));
    	printf("Rightmost set bit of %d: %d\n", x, get_rightmost_set_bit(x));
    	printf("Rightmost unset bit of %d: %d\n", x, get_rightmost_unset_bit(x));
    	printf("Mask for even bits: 0x%X\n", mask_even_bits());
	printf("Mask for odd bits: 0x%X\n", mask_odd_bits()); 
    return 0;
}
