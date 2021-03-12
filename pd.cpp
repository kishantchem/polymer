#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	   std::ifstream file;
	   double TIME[40001];
           double GOR[40001];
	   double min, max,value1,value2;
	   int i=0;   
	   file.open("RG.dat");
         
	         while(!file.eof())
                     {
		    file >> TIME[i] >> GOR[i];
		       cout << TIME[i] <<"\t" << GOR[i] <<endl; // echo of input / proof it works
		
		      
		       if(i==1)
			{
		        if(GOR[i] < GOR[i-1])
		        {
			min=GOR[i];
			max=GOR[i-1];
			cout<<"min=="<<min<<endl;
		        }
			else 
			{
			min=GOR[i-1];
			max=GOR[i];
			}
			}
		        
                       if(i>1)
			 {
                         if(GOR[i]<min)
				 min=GOR[i];
			 if(GOR[i]>max)
				 max=GOR[i];
			 } 

		          //system("pause");
			  //   file.close();
			  //      return 0;
			  //     
		        i++;
			count=i;
		       }

                       cout<<"total data points="<<i<<endl;
		       cout<<"minimum value="<<min<<endl;
		       cout<<"maximum value="<<max<<endl;
                    }

///// BIN SIZE ////
int Nbin=100;
double binlength=(max-min)/Nbin;
double Pcount[100];
for(i=0;i<count;i++)
   {
	l= int ((GOR[i]-min)/binlength);   
    Pcount[l]=Pcount[l]+1;
   }

for(l=0;l<count;l++)
   {
    cout<<min+l*binlength<<'\t'<<Pcount[l]<<endl;	        

   }



