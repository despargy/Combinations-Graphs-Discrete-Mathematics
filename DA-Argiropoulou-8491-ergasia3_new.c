//DEV C++ Ver 5.11 (2015)
//A.M 8491 Despina Ekaterini Argiropoulos
//!!! SOS to be compiled with language standard ISO C99
// VLA matrix
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int main(void)
{
	int n;
	printf("give me the number 'n' of edges\n");
	scanf("%d",&n);
	
	int table[n];		//pinakas me dedomena ton bathmo gia tin kathe korifi
	int t[n];			//boithitikos pinakas 
	int d[n];			//periexei times gia tis arxikes theseis ston table
	int neighb[n][n];	//pinakas geitniasis, theseis antistoixes me tin seira pou dothikan oi korifes ston table[]
	int i,j,sum=0,k,s,c,e,swap;
	bool stop=false,end=false;	//metablites elegxou
	
	printf("give me the edges of the %d peaks\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &table[i]);		//dexomai tis akmes kathe korifis
		sum=sum+table[i];			//gia enan arxiko elegxo ean to athroisma twn akmwn einai 2x
		if (table[i]>=n || table[i]<0) stop=true;	//arnitikos bathmos i megaluteros tou n aporiptetai
	}
	
	stop=stop || sum%2!=0;
	if (!stop)		//mikros-profaneis-eukolos elegxos, alliws sigoura den einai grafiki
	{
		for(i=0;i<n;i++)		
		{
			t[i]=table[i];		//gia na min alliwsoume ton table[], tha doulepsoume me t[]
			d[i]=i;				//arxikopoioume ton d pou deixnei to i stoixeio tou t[] se poia thesi brisketai ston arxiko pinaka table[]	 t[i]=table[d[i]]
			for(j=0;j<n;j++)
			{
				neighb[i][j]=0;		//arxikopoioume ton pinaka geitniasis, ola ta stoixeia 0
			}
		}
		for (c=0;c<n;c++)		//taksinomisi kata fthinousa seira tou t[] kai antistoixi allagi ston d[]
 		{
    		for (e=0;e<n-c-1;e++)
    		{
      			if (t[e]<t[e+1]) 
      			{
        		swap=t[e];
        		t[e]=t[e+1];
        		t[e+1]=swap;
        		
        		swap=d[e];
        		d[e]=d[e+1];
        		d[e+1]=swap;
     			}
    		}
  		}
 /*		//GIA ELEGXO SBISTE TA EKSOTERIKA MARKS
		for(i=0;i<n;i++)	
		{
			printf("fthinousa %d \t",t[i]);
		}
		printf("\n ok mpike\n");		//check check meta tin prwti taksinomisi
		for(i=0;i<n;i++)
		{
			printf("to %d == %d\n",t[i],table[d[i]]);
		}
*/		

		while(!stop && !end)	//oso min stamatiseis kai oso den exoume teleiwsei-> sunexise
		{
			k=0;	
			j=d[0];			//pame na gemisoume tin stili tis 0 korifis kathe fora	
			while(k<t[0])	//kathe fora gia to max stoixeio afairoume mia monada apo ta epomena t[0] stoixeia
			{
				k++;	//metrame apo posa epomena exoume afairesei mia monada
				t[k]--;	//meiwnoume kata 1 ton bathmo tis korifis k
				i=d[k];	
				neighb[i][j]=1;		//sundeoume to 
				neighb[j][i]=1;	//epeidi einai summetrikos
			}
			t[0]=0;
			for (c=0;c<n;c++)	//taksinomoume sto telos kathe afairesis tis korifis me  megalutero bathmo, olous tous bathmous pou menoun 
 			{
    			for (e=0;e<n-c-1;e++)
    			{
    				if (t[e]<t[e+1]) 
    				{	
   						swap=t[e];
   						t[e]=t[e+1];
						t[e+1]=swap;   		
        				swap=d[e];
        				d[e]=d[e+1];
        				d[e+1]=swap;
     				}
    			}
 			}	
 			//GIA ELEGXO
 			printf("\n");
			for(c=0;c<n;c++)
		  	{
  				printf("%d \t",t[c]);	
			}
 /*			printf("\n");
			for(c=0;c<n;c++)
		  	{
  				printf("%d \t",d[c]);	
			}
*/			
			
			c=0;
			while(!stop && c<n)	
			{
				if(t[c]<0) stop=true;	//elegxo an brw estw kai enan arnitiko bathmo korifis, stamataw to programma
				c++;
			}
			end=true;	//thewrw pws exw teleiwsei kai oloi oi bathmoi einai miden
			for(c=0;c<n;c++)
			{
				if (t[c]!=0) end=false;	//an brw estw kai enan bathmo diaforo tou midenos, lew pws den exw teleiwsei kai thetw end=false
			}
		
		}	
			
	}	
	 
	if(stop)	//teliko minima
	{
		printf("den einai grafiki \n");
	}
	else if(end)
	{
		printf("\n einai grafiki \n \n \n");
		//PINAKAS GEITNIASIS-EKTUPWSI
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d \t",neighb[i][j]);
			}
			printf("\n \n");
		}
		
	}
	
	
	return 0;
}
