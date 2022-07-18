#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int* BuildMatch(char* Patt){
	int i = 0;
	int indexLen = 1;
	int len = strlen(Patt);
	int Match[len];
	Match[0] = 0;
	//Match = (char*)malloc(sizeof(int)*len);
	while(i<len){
		if(Patt[indexLen] == Patt[i]){
			Match[i++] = indexLen++;
		}else{
			if(indexLen == 0){
				Match[i++] = 0;
			}else{
				indexLen = Match[i-1];
			}
		}	    
	}
	return Match;
} 

#define NotFound -1


typedef int Position;

int KMP(char* string, char* pattern){
	int n = strlen(string);
	int m = strlen(pattern);
	
	Position s,p,*match;
	
	if(n<m) return NotFound;
	*match = BuilidMatch(pattern);
	
	s = p = 0;
	while(s<n&&p<m){
		if(string[s] == pattern[p]){
			s++;
			p++;
		}else if(p>0)
	        p = match[p-1];
	    else 
	       s++;
	}
    return (p==m)? (s-m):NotFound;	
}

// ±º‰∏¥‘”∂»O(n+m) 

