#include "aditionals.h"



double  ancho   =0.9,
        alto    =0.9;
cubo *_c=new cubo(20);
float dt=0.1;
float tfin=100;
double T=1.0;


double gasdev () {
     static bool available = false;
     static double gset;
     double fac, rsq, v1, v2;
     if (!available) {
          do {
               v1 = 2.0 * rand() / double(RAND_MAX) - 1.0;
               v2 = 2.0 * rand() / double(RAND_MAX) - 1.0;
               rsq = v1 * v1 + v2 * v2;
          } while (rsq >= 1.0 || rsq == 0.0);
          fac = sqrt(-2.0 * log(rsq) / rsq);
          gset = v1 * fac;
          available = true;
          return v2*fac;
     } else {
          available = false;
          return gset;
     }
}

void reescalar_velocidades()
{
    int num_mol=_c->num_moleculas;
    double vSqdSum = 0;
    for(int i=0;i<num_mol;i++)
    {
        vSqdSum += pow(_c->vec_cubo[i]->vx,2);
        vSqdSum += pow(_c->vec_cubo[i]->vy,2);
    }

    double lambda = sqrt( 3 * (num_mol-1) * T / vSqdSum );
    for (int i = 0; i < num_mol; i++)
    {
        _c->vec_cubo[i]->vx*=lambda;
        _c->vec_cubo[i]->vy*=lambda;
    }

}

void inicializar_velocidades()
{
    int num_mol=_c->num_moleculas;

    for(int i=0;i<num_mol;i++)
    {
        _c->vec_cubo[i]->vx=gasdev();
        _c->vec_cubo[i]->vy=gasdev();
    }

    double vCM[2] = {0, 0};
    for(int i=0;i<num_mol;i++)
    {
        vCM[0]+=_c->vec_cubo[i]->vx;
        vCM[1]+=_c->vec_cubo[i]->vy;
    }


    for (int i = 0; i < 2; i++)
        vCM[i] /= num_mol;

    for(int i=0;i<num_mol;i++)
    {
        _c->vec_cubo[i]->vx=vCM[0];
        _c->vec_cubo[i]->vy=vCM[1];
    }
}



void colision_limite(molecula * mol, double vx, double vy)
{
    double radio=mol->radio;

    if(mol->x+radio > ancho )
    {
        mol->x=ancho;
        mol->oldx=mol->x+vx;
    }
    else if(mol->x+radio < -ancho)
    {
        mol->x=-ancho;
        mol->oldx=mol->x+vx;
    }
    else if(mol->y+radio > alto)
    {
        mol->y = alto;
        mol->oldy=mol->y+vy;
    }
    else if(mol->y+radio < -alto)
    {
        mol->y= -alto;
        mol->oldy=mol->y+vy;
    }

}


double  distancia_centro(molecula *mol1, molecula *mol2)
{
    double distancia= sqrt(pow(mol1->x-mol2->x,2)+pow(mol1->y-mol2->y,2));
    return distancia-mol1->radio-mol2->radio;
}


void colision_moleculas(cubo *contenedor)
{
    int num_mol=contenedor->num_moleculas;
    for(int i=0;i<num_mol;i++)
    {
        for(int j=i+1;j<num_mol;j++)
        {
            molecula *mol1=contenedor->vec_cubo[i];
            molecula *mol2=contenedor->vec_cubo[j];
            double distancia = distancia_centro(mol1,mol2);
            if(distancia<=0)
            {
                //cout<<distancia<<endl;
            }
        }
    }
}

void actualizar_moleculas(cubo *contenedor)
{
    for(int i=0;i<contenedor->num_moleculas;i++)
    {
        molecula *mol=contenedor->vec_cubo[i];
        /*
        mol->x+=mol->vx*dt+0.5*mol->ax*dt*dt;
        mol->y+=mol->vy*dt+0.5*mol->ay*dt*dt;
        */

        double vx=mol->x - mol->oldx;
        double vy=mol->y - mol->oldy;

        mol->oldx=mol->x;
        mol->oldy=mol->y;

        mol->x+=vx;
        mol->y+=vy;

        colision_limite(mol, vx, vy);
        //colision_moleculas(contenedor);
    }
}

void dibujar_moleculas()
{
    for(int i=0;i<_c->num_moleculas;i++)
        dibujar(_c->vec_cubo[i]);
}

void correr()
{
    for(float tiempo=0;tiempo<tfin;tiempo+=dt)
    {
        limpiar();

        actualizar_moleculas(_c);
        dibujar_moleculas();
        Sleep(10);
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(600,600);
    glutCreateWindow("MD");
    correr();
    glutMainLoop();
    return 0;
}
