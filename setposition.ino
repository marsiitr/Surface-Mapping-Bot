void setposition(int p)
{ 
  if(p>posi)
  {
    for(int i=posi;i<=p;i++)
    {
      myservo.write(i);
      delay(20);
    }
  }
  else
  {
     for(int i=posi;i>=p;i--)
    {
      myservo.write(i);
      delay(20);
    }
  }
  posi=p;
}

