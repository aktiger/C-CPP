#include"iostream"
//#include"stdlib.h" 
using namespace std;
int a[69];//存小棒长大小最好大于64
int visited[69];//标记小棒是否被用
int n;//小棒个数 
int cmp(const void *a,const void *b)
{
    return *(int*)b-*(int*)a; 
} 
/*DFS:递归搜索，以剩下小棒数和拼接一根棒所需长度作为递归参数*/ 
int DFS(int len,int remains_len,int num)/*作为搜索的棒长len，拼成len长的棒还需的长度remains_len，剩下的未作为拼接的小棒个数*/
{
    if(remains_len==0&&num==0)/*当还需长度为0且未作接接的小棒个数为0时，说明拼接成功*/
    return len;
    if(remains_len==0)/*当完成拼接一个棒时，要重新进行下一根木棒拼接，给remains_len重新赋值*/
    remains_len=len;
    for(int i=0;i<n;i++)
    {
            if(visited[i]==1)/*已经作为成功拼接的小棒，不再作为拼接对象*/ 
            continue; 
            if(remains_len>=a[i])
            {
                 visited[i]=1;/*暂时标记为已经用了*/ 
                 if(DFS(len,remains_len-a[i],num-1))/*当接受这根小棒a[i]，能完成所有任务，则返回成功拼接棒长*/ 
                 return len;
                 visited[i]=0;/*当用a[i]不能完成任务就不用此棒，将其标记为该步未用此棒*/ 
                 if(a[i]==remains_len||len==remains_len)/*a[i]=remains_len或remians_len=len时本来表示即将拼成一根棒，或刚进行新一轮拼接(即if中判断的是主问题性质完全相同的子问题）但经过上面的if判断，子问题不能完成所有任务，
                 那么整体不可能完成任务，不再考虑，搜索失败（剪枝）*/ 
                 break; 
                 while(a[i]==a[i+1])/*当a[i]不能完成任务，与它相同的小棒也不能完成任务（剪枝） */
                 i++; 
            } 
    } 
    return 0; 
} 
int main()
{
    while(cin>>n&&n)
    {
                    int sum=0;//所有小棒长度
                    int len,k;
                    for(int i=0;i<n;i++)
                    {
                            cin>>a[i];
                            sum+=a[i]; 
                    } 
                    qsort(a,n,sizeof(int),cmp);
                    for(len=a[0];len<=sum;len++)
                    {
                        memset(visited,0,sizeof(visited));/*每次尝试都要置所有小棒为可用*/
                        if(sum%len==0)
                        {
                                     k=DFS(len,0,n); 
                                      if(k) 
                                        break; 
                        }
                    }
                    cout<<k<<endl; 
    } 
    return 0;
}