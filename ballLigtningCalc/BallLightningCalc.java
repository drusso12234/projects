import java.io.*;
import java.util.*;

#include <stdio.h>
#include <locale.h>

public class BallLightningCalc {

  private static final int  HITINTERVAL = 150;
  private static final int ENEMYRADIUS = 3; //19-25 -- Centered at 22

  public static void main(String[] args) {
    double radius = Double.valueOf(args[0]) * 22;
    double projSpeed = Double.valueOf(args[1]) * 48;
    double avgHit = Double.valueOf(args[2]);
    double ballPerSecond = Double.valueOf(args[3]);
    double simulationTime = Double.valueOf(args[4]) * 1000;
    int msecPerBall = (int)(1000 / ballPerSecond);

    //System.out.printf("Radius = %f\nProjSpeed = %f\navgHit = %f\n", radius, projSpeed, avgHit);
    ArrayList<BoL> arr = new ArrayList<BoL>();

    /*for (double i = 0; i <= simulationTime; i += msecPerBall){
      arr.add(new BoL(radius, projSpeed, avgHit));
    }*/
    double i = 0;
    while (i <= simulationTime){
      if(i % msecPerBall == 0){
        arr.add(new BoL(radius, projSpeed, avgHit));
        System.out.printf("%.1f: Ball #%d\n", i, arr.size());
      }
      for(BoL s : arr){
        s.tick();
      }
      i++;
    }
    double yeet = 0;
    for (BoL g : arr){
      yeet += g.totalDamage;
    }
    double dps = yeet/Double.valueOf(args[4]);
    System.out.printf("Total damage: %'.3f\nDPS: %'.3f\n", yeet, dps);


}


}

class BoL{
  private double projSpeed;
  private double radius;
  private double avgHit;
  private double pos = 0;
  private int ballTime = 0;
  public double totalDamage = 0;
  private double unitsPerMsec = projSpeed / 1000;
  public BoL(double w, double c, double p){
    radius = w;
    projSpeed = c;
    avgHit = p;
  }
  public void tick(){
    ballTime++;
    pos += unitsPerMsec;

    if (ballTime % 150 == 0 && checkPos(pos))
      totalDamage += avgHit;
  }
  private boolean checkPos(double pos){
    double minRange = pos - radius;
    double maxRange = pos + radius;
    double[] checkArr = new double[]{19.0,20.0,21.0,22.0,23.0,24.0,25.0};
    for (double x : checkArr){
        if (minRange <= x)
          return true;
      }
    return false;
    }
}
