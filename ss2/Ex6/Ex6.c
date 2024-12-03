 #include <stdio.h>
 int main (){
 	int n,m,a;
    int arr[n];
    do {
        scanf("%d", &n);
    } while (n <= 0 || n > 1000);
 
 	int result[m+n];
 	for(int i =0 ; i<n;i++){
 		scanf("%d",&a);
 		arr[i]=a;
 		result[i]=a;
	 };
	scanf("%d",&m);
	int arr2[m];
	 for(int i =0 ; i<m;i++){
 		scanf("%d",&a);
 		arr2[i]=a;
 		result[i+n]=a;
	 };
    	printf("Ket qua la");
	for(int i =0 ; i<n+m;i++){
 		printf("%d ",result[i]);
	};
	
 }