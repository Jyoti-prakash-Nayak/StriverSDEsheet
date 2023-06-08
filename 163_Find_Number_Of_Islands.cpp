
using namespace std;
int DR[8]={0,+1,0,-1,+1,-1,+1,-1};
int DC[8]={+1,0,-1,0,+1,-1,-1,+1};
bool valid(int newR,int newC,int n,int m,int** arr){
   if(newR<0 || newC<0 || newR>=n || newC>=m)
      return false;
   return true;
}
void dfs(int i,int j,int n,int m,int** arr){
   arr[i][j]=0;
   for(int k=0;k<8;k++){
      int ci=i+DR[k];
      int cj=j+DC[k];
      if(ci>=0 && ci<n && cj>=0 && cj<m && arr[ci][cj]==1){
         dfs(ci,cj,n,m,arr);
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int res=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(arr[i][j]==1){
            res++;
            dfs(i,j,n,m,arr);
         }
      }
     
   }
    return res;
}
