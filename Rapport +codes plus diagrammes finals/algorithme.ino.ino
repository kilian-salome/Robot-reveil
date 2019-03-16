void loop() {//algorithme du code
  DS3231_get(&t);
  val = digitalRead(button);
  cm = sonar.ping_cm();
  afficherOeil();
  
  if (cond == 1) {
    
    if (le bluetooth envoie quelque chose) {
      recupererAlarm();
      cond = 0;
      //quand le module a reçu une alarme et permet de déclencher cond =2
    }
    
    if (la main est devant le robot) {
      afficherDateMONI(t);
      afficherHeure();
    }
    
  }

  else {
    
    if ( meme Heure et  cond == 0) {
      cond = 2;
      //condition pour déclencher de réveil: lorsque cond =2 le robot roule
    }
    
    if (cond == 2) {
      faireSonnerReveil();
      faireRoulerrobot();
      afficherMessageReveil();
      
      if (le bouton est appuyé) {
        Moteur A - pas tourner
        Moteur B - pas tourner
        cond = 1;
        //sert pour éteindre le reveil lorsque le bouton est appuyé
      }
    }
  }
}
