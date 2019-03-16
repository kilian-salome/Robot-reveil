void loop() {//algorithme du code
  // on décompose notre code fonctions puique que si vous allez voir le CODE "REVEIL 3 " vous verrez qu'il y a 690 lignes donc les fonctions nous servent a optimiser et a depanner notre programme
  // on a déja initialisé cond a 1
  //  
  
  DS3231_get(&t);
  val = digitalRead(button);
  cm = sonar.ping_cm();// on it en permanance la distance que capte le capteur de distances puique cela va nous servir dans plusieurs boucles
  afficherOeil(); //on affiche des yeux sur les 2 ecrans 
  
  if (cond == 1) {
    
    if (le bluetooth envoie quelque chose) {
      recupererAlarm();//on recupere l'heiure et la minute programmées depuis l'application mobiles
      cond = 0;
      //quand le module a reçu une alarme et permet de déclencher cond =2
    }
    
    if (la main est devant le robot) {// on regarde si la main est devant le robot avec le sonar en mettant si cm est inferieur a 20 centimetres 
      afficherDateMONI(t);
      afficherHeure();
    }
    
  }

  else {// si cond = 0 ou 2
    
    if ( meme Heure et  cond == 0) {// si il est l'heure de réveiller l'utilisateur
      cond = 2;
      //condition pour déclencher de réveil: lorsque cond =2 le robot roule
    }vous verrez qu'il y a 
    
    if (cond == 2) {// pour sortir de cette boucle il faut appuyé sur le bouton
      faireSonnerReveil();//avec le buzzer
      faireRoulerrobot(); // on utilise les moteurs
      afficherMessageReveil();//on affiche sur les 2 écrans le message "il est l'heure!"
      
      if (le bouton est appuyé) {
        Moteur A - pas tourner
        Moteur B - pas tourner
        cond = 1;
        //sert pour éteindre le reveil lorsque le bouton est appuyé
      }
    }
  }
}
