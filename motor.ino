//All the values are set by tuning my steppers.
//Feel free to change the values.

void turnright(void){
  Stepperleft.setSpeed(60);
  Stepperright.setSpeed(60);

  for(int i = 1 ; i <= 175 ; i++){
    Stepperright.step(-1);
    Stepperleft.step(1);
  }
}

void turnleft(void){
  Stepperleft.setSpeed(60);
  Stepperright.setSpeed(60);

  for(int i = 1 ; i <= 175 ; i++){
    Stepperright.step(1);
    Stepperleft.step(-1);
  }
}

void forward(void){
  Stepperleft.setSpeed(60);
  Stepperright.setSpeed(60);

  for(int i = 1 ; i <= 235 ; i++){
    Stepperright.step(1);
    Stepperleft.step(1);
  }
}

void turnaround(void){
  Stepperleft.setSpeed(60);
  Stepperright.setSpeed(60);

  for(int i = 1 ; i <= 400 ; i++){
    Stepperright.step(1);
    Stepperleft.step(-1);
  }
}
