  int directionchange(int a[],const int f,int dir){ 
    if(a[0]>a[2] && a[0]>0){   
      turnleft();
      dir=dir-1;;
    }
    else if(a[2]>=a[0] && a[2]>0){ 
      turnright();
      dir=dir+1;
    }         
    else{ 
      turnaround();
      dir +=2;
    }
    if(dir==0) dir=4;
    if(dir>=5) dir = dir-4;
    return dir;
  }
