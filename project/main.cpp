#include "aditionals.h"


cubo *_c=new cubo(20);
double  ancho   =0.9,
        alto    =0.9;

void colision_limite(molecula * mol, double vx, double vy)
{
    double radio=mol->radio;

    if(mol->x+radio > ancho )
    {
        mol->x=ancho;
        mol->oldx=mol->x+vx;
    }
    else if(mol->x+radio < -0.9)
    {
        mol->x=-0.9;
        mol->oldx=mol->x+vx;
    }
    else if(mol->y+radio > alto)
    {
        mol->y = alto;
        mol->oldy=mol->y+vy;
    }
    else if(mol->y+radio < -0.9)
    {
        mol->y= -0.9;
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
    thread *vec_th[contenedor->num_moleculas];

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
                cout<<distancia<<endl;
            }
        }
    }
}

void actualizar_moleculas(cubo *contenedor)
{
    for(int i=0;i<contenedor->num_moleculas;i++)
    {
        molecula *mol=contenedor->vec_cubo[i];

        double vx=mol->x - mol->oldx;
        double vy=mol->y - mol->oldy;

        mol->oldx=mol->x;
        mol->oldy=mol->y;

        mol->x+=vx;
        mol->y+=vy;

        colision_limite(mol, vx, vy);
        colision_moleculas(contenedor);
    }
}


void correr()
{
    while(true)
    {
        limpiar();
        actualizar_moleculas(_c);
        for(int i=0;i<_c->num_moleculas;i++)
        {
            dibujar(_c->vec_cubo[i]);
        }
        Sleep(10);
    }
}

void posicion()
{
    while(true)
    {
        cout<<"x : "<<_c->vec_cubo[0]->x<<endl;

    }
}



int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutInitWindowSize(800,800);
    glutCreateWindow("MD");
    glutDisplayFunc(correr);

    glutPostRedisplay();
    glFlush();

    //thread foo(posicion);

    glutMainLoop();
    //foo.join();
    return 0;
}

