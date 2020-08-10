// NBFM Modulator + Upconverter standard crystal values finder V1.0 Luigi Findanno 2020

#include <stdio.h>
#include <stdlib.h>

const double xtal[] = {3.579545, 3.6864, 3.84, 4, 4.194303, 4.8, 4.9152,
				5, 6, 7.3728, 8, 8.8672, 10, 10.24, 10.7, 10.245, 11.0592, 12,
				12.288, 12.8, 13.56, 14.31818, 14.7456, 16, 18,
				18.432, 19.2, 19.6608, 20, 20.48, 24, 24.576, 
				25, 27, 28, 40, 48};


int main(int argc, char *argv[]) {
	
	double fout;
	double tollerance = 0.01; // +- 10 KHz tollerance
	double fmod, flo;
		
	double fplus, fminus;
	double foutmin, foutmax;
	int values = sizeof(xtal) / sizeof(xtal[0]);
	
	printf("NBFM Modulator + Upconverter standard crystal values finder V1.0 Luigi Findanno 2020\n");
	printf("enter the output frequency in MHz ");
	
	scanf("%lf", &fout);

	foutmin = fout - tollerance;
	foutmax = fout + tollerance;
	
	for (int mod=0; mod<values; mod++){
		for (int lo=0; lo<values; lo++){

			for (int loarm = 1; loarm <=7; loarm += 2){

				flo = xtal[lo] * loarm;

				for (int modarm = 1; modarm <=7; modarm +=2){

					fmod = xtal[mod] * modarm;
					
					fplus = flo + fmod;
					if (fplus >= foutmin && fplus <= foutmax){
						printf("\nFrequency %lf sum of:\n", fplus);
						printf("Upconverter LO xtal = %lf MHz at %d harmonic (%lf)\n", xtal[lo], loarm, flo);
						printf("Modulator xtal = %lf MHz at %d harmonic (%lf)\n", xtal[mod], modarm, fmod);
					}

					fminus = flo - fmod;
					if (fminus >= foutmin && fminus <= foutmax){
						printf("\nFrequency %lf subtraction of:\n", fminus);
						printf("Upconverter LO xtal = %lf MHzat %d harmonic (%lf MHz)\n", xtal[lo], loarm, flo);
						printf("Modulator xtal = %lf MHz at %d harmonic (%lf MHz)\n", xtal[mod], modarm, fmod);
					}
				}				
			}
		}
	}
	return 0;
}

