#include<iostream>
#include<vector>
#include<utility>
#include<list>
using namespace std;
int n;
list<pair<int,bool> >  feed;
int msb(int t,int arrbin[][8]){
	int count0=0,count1=0;
    for(int i=0;i<n;i++)
    {
        if(( arrbin[i][7-t] )==0) count0++;
        else count1++;
    }
    if(count0>count1){
    	return 0;
	}
	else {
		return 1;
	}
}
void feedback(int z,int t,int arrbin[][8]){
	list<pair<int,bool> > :: iterator it,it2;	
	for(it=feed.begin();it!=feed.end();it++){
			int a = (*it).first;		
			if(z!=( arrbin[a][7-t] ) && (*it).second==true){
				if(z>(arrbin[a][7-t])){
					for(int i=6-t;i>=0;i--){
						arrbin[a][i]=0;					
					}							
				}
				else{
					for(int i=6-t;i>=0;i--){
						arrbin[a][i]=1;
					}					
				}
				(*it).second=false;
			}		
	}
}
int main(){
	
	  /*Declarations */	  
	cout<<"enter size of window over which you want to implement median filter\n";
	int x;
	vector<int> vecnum;
	cin>>n;
	cout<<"enter the values of pixels\n";
	int arrbin[n][8]={0,0,0,0,0,0,0,0};
	for(int i=0;i<n;++i){
	
	}
	/*-----------------------------*/
			
	/*Binary conversion*/
    for(int i=0;i<n;i++)
    {
    	cin>>x;
		vecnum.push_back(x);
		cout<<":--\t";
       // int num = vecnum[i];
        for(int j=0;j<8;j++)
        {
            if(x!=0)
            {
                arrbin[i][j] = x%2;
                x /= 2;
            }
           cout<<arrbin[i][j]<<" ";
        }
cout<<endl;
    }
    
		
	 /*B V algorithm followed by feedback and elimination */
	for(int c=0;c<n;c++){
		feed.push_back(make_pair(c,true));
	}
	 
	vector<int> res;
	for(int t=0;t<8;++t){
		int z=msb(t,arrbin);
		feedback(z,t,arrbin);
		res.push_back(z);
	}		
	/*-----------------------------*/
			
	cout<<"MEDIAN VALUE OF PIXEL USING BIT VOTER ALGORITHM :-\n\n\n\t\t\t ";	
	for(int i=0;i<res.size();i++)
		 cout<<res[i]<<" ";

    return 0;	
}
