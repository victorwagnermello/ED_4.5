#include <stdio.h>
#include<string.h>


   main() {
	
	char q[400],p[400],str[400],aux;
	
	int n,topo,i,front,a;
	scanf("%d",&n);
	for(int a=0;a<n;a++){
	
	
		front 	=	0;
		topo	=	0;
		scanf("%s ",&str);
		for(i=0;i<strlen(str);i++)
		{
           if(str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i]!='^'&&str[i]!='('&&str[i]!=')')
           {
           	  q[front++]	= str[i];
           }
           else
           {
           	   if(str[i]=='+')
           	   {
           	   	  while(topo>0)
           	   	  {
           	   	  	aux	=	p[topo-1];
           	   	  	if(aux	!=	'(')
           	   	  	{
           	   	  	   q[front++]	=	aux;
           	   	  	   topo--;
           	   	  	}
           	   	  	else
           	   	  	  break;
           	   	  }
           	   }
               else if(str[i]=='-')
           	   {
           	   	  while(topo>0)
           	   	  {
           	   	  	aux	=	p[topo-1];
           	   	  	if(aux != '+'&&aux != '(')
           	   	  	{
           	   	  	    q[front++]	=	aux;
           	   	  	    topo--;
           	   	  	}
           	   	  	else
           	   	  	   break;
           	   	  }
           	   }
               else if(str[i]=='*')
           	   {
           	   	  while(topo>0)
           	   	  {
           	   	  	aux	=	p[topo-1];
           	   	  	if(aux != '+'&&aux != '-'&&aux != '(')
           	   	  	{
           	   	  	    q[front++]	=	aux;
           	   	  	    topo--;
           	   	  	}
           	   	  	else
           	   	  	  break;
           	   	  }
           	   }
               else if(str[i]=='/')
           	   {
           	   	  while(topo>0)
           	   	  {
           	   	  	aux	=	p[topo-1];
           	   	  	if(aux != '+'&&aux != '-'&&aux != '*'&&aux != '(')
           	   	  	{
           	   	  	    q[front++]	=	aux;
           	   	  	    topo--;
           	   	  	}
           	   	  	else
           	   	  	  break;
           	   	  }
           	   }
               else if(str[i]=='^')
           	   {
           	   	  while(topo>0)
           	   	  {
           	   	  	aux	=	p[topo-1];
           	   	  	if(aux != '+'&&aux != '-'&&aux != '*'&&aux != '/'&&aux != '(')
           	   	  	{
           	   	  	    q[front++]	=	aux;
           	   	  	    topo--;
           	   	  	}
           	   	  	 else
           	   	  	   break;
           	   	  }
           	   }
               else if(str[i]==')')
           	   {
           	   	  while(p[topo-1]!='(')
           	   	  {
           	   	  	aux	=	p[topo-1];
           	   	  	q[front++]	=	aux;
           	   	  	topo	=	topo	-1;
           	   	  }
           	   	  topo	=	topo	-	1;
           	   }
           	   if(str[i] !=')')
           	      p[topo++]	= str[i];
           }
		}
		while(topo>0)
		{
		   q[front++]	=  p[topo-1]	;
		   topo	=	topo-1;
		}
		q[front]	=	'\0';
		printf("%s\n",q);
	}
	return 0;
}
 
