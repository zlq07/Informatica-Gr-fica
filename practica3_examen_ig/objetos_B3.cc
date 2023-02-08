//**************************************************************************
// Práctica 3
//**************************************************************************

#include "objetos_B3.h"
#include "file_ply_stl.hpp"
#include <time.h>

//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
  //**** usando vertex_array ****
  glPointSize(grosor);
  glColor3f(r, g, b);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glDrawArrays(GL_POINTS, 0, vertices.size());

  /*int i;
  glPointSize(grosor);
  glColor3f(r,g,b);
  glBegin(GL_POINTS);
  for (i=0;i<vertices.size();i++){
    glVertex3fv((GLfloat *) &vertices[i]);
    }
  glEnd();*/
}

//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}

//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
  //**** usando vertex_array ****
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glLineWidth(grosor);
  glColor3f(r, g, b);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glDrawElements(GL_TRIANGLES, caras.size() * 3, GL_UNSIGNED_INT, &caras[0]);

  /*int i;
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glLineWidth(grosor);
  glColor3f(r,g,b);
  glBegin(GL_TRIANGLES);
  for (i=0;i<caras.size();i++){
    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
    }
  glEnd();*/
}

//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
  int i;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(r, g, b);
  glBegin(GL_TRIANGLES);
  for (i = 0; i < caras.size(); i++)
  {
    glVertex3fv((GLfloat *)&vertices[caras[i]._0]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._1]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._2]);
  }
  glEnd();
}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores()
{
  int i;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  for (i = 0; i < caras.size(); i++)
  {
    glColor3f(colores_caras[i].r, colores_caras[i].g, colores_caras[i].b);
    glVertex3fv((GLfloat *)&vertices[caras[i]._0]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._1]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._2]);
  }
  glEnd();
}

void _triangulos3D::draw_solido_scooter(float r, float g, float b)
{
  int i;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(r, g, b);
  glBegin(GL_TRIANGLES);
  for (i = 0; i < caras.size(); i++)
  {
    glVertex3fv((GLfloat *)&vertices[caras[i]._0]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._1]);
    glVertex3fv((GLfloat *)&vertices[caras[i]._2]);
  }
  glEnd();
}
//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r, float g, float b, float grosor)
{
  switch (modo)
  {
  case POINTS:
    draw_puntos(r, g, b, grosor);
    break;
  case EDGES:
    draw_aristas(r, g, b, grosor);
    break;
  case SOLID:
    draw_solido(r, g, b);
    break;
  case SOLID_COLORS:
    draw_solido_colores();
    break;
  case SOLID_COLORS_SCOOTER:
    draw_solido_scooter(r, g, b);
    break;
  }
}

//*************************************************************************
// asignación colores
//*************************************************************************

void _triangulos3D::colors_random()
{
  int i, n_c;
  n_c = caras.size();
  colores_caras.resize(n_c);
  srand(time(NULL));
  for (i = 0; i < n_c; i++)
  {
    colores_caras[i].r = rand() % 1000 / 1000.0;
    colores_caras[i].g = rand() % 1000 / 1000.0;
    colores_caras[i].b = rand() % 1000 / 1000.0;
  }
}

//*************************************************************************

void _triangulos3D::colors_chess(float r1, float g1, float b1, float r2, float g2, float b2)
{
  int i, n_c;
  n_c = caras.size();
  colores_caras.resize(n_c);
  for (i = 0; i < n_c; i++)
  {
    if (i % 2 == 0)
    {
      colores_caras[i].r = r1;
      colores_caras[i].g = g1;
      colores_caras[i].b = b1;
    }
    else
    {
      colores_caras[i].r = r2;
      colores_caras[i].g = g2;
      colores_caras[i].b = b2;
    }
  }
}

//*************************************************************************
// objetos o modelos
//*************************************************************************

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
  // vertices
  vertices.resize(8);
  vertices[0].x = -tam;
  vertices[0].y = -tam;
  vertices[0].z = tam;
  vertices[1].x = tam;
  vertices[1].y = -tam;
  vertices[1].z = tam;
  vertices[2].x = tam;
  vertices[2].y = tam;
  vertices[2].z = tam;
  vertices[3].x = -tam;
  vertices[3].y = tam;
  vertices[3].z = tam;
  vertices[4].x = -tam;
  vertices[4].y = -tam;
  vertices[4].z = -tam;
  vertices[5].x = tam;
  vertices[5].y = -tam;
  vertices[5].z = -tam;
  vertices[6].x = tam;
  vertices[6].y = tam;
  vertices[6].z = -tam;
  vertices[7].x = -tam;
  vertices[7].y = tam;
  vertices[7].z = -tam;

  // triangulos
  caras.resize(12);
  caras[0]._0 = 0;
  caras[0]._1 = 1;
  caras[0]._2 = 3;
  caras[1]._0 = 3;
  caras[1]._1 = 1;
  caras[1]._2 = 2;
  caras[2]._0 = 1;
  caras[2]._1 = 5;
  caras[2]._2 = 2;
  caras[3]._0 = 5;
  caras[3]._1 = 6;
  caras[3]._2 = 2;
  caras[4]._0 = 5;
  caras[4]._1 = 4;
  caras[4]._2 = 6;
  caras[5]._0 = 4;
  caras[5]._1 = 7;
  caras[5]._2 = 6;
  caras[6]._0 = 0;
  caras[6]._1 = 7;
  caras[6]._2 = 4;
  caras[7]._0 = 0;
  caras[7]._1 = 3;
  caras[7]._2 = 7;
  caras[8]._0 = 3;
  caras[8]._1 = 2;
  caras[8]._2 = 7;
  caras[9]._0 = 2;
  caras[9]._1 = 6;
  caras[9]._2 = 7;
  caras[10]._0 = 0;
  caras[10]._1 = 1;
  caras[10]._2 = 4;
  caras[11]._0 = 1;
  caras[11]._1 = 5;
  caras[11]._2 = 4;

  // colores de las caras
  colors_random();
}

//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{
  int i;
  // vertices
  vertices.resize(5);
  vertices[0].x = -tam;
  vertices[0].y = 0;
  vertices[0].z = tam;
  vertices[1].x = tam;
  vertices[1].y = 0;
  vertices[1].z = tam;
  vertices[2].x = tam;
  vertices[2].y = 0;
  vertices[2].z = -tam;
  vertices[3].x = -tam;
  vertices[3].y = 0;
  vertices[3].z = -tam;
  vertices[4].x = 0;
  vertices[4].y = al;
  vertices[4].z = 0;

  caras.resize(6);
  caras[0]._0 = 0;
  caras[0]._1 = 1;
  caras[0]._2 = 4;
  caras[1]._0 = 1;
  caras[1]._1 = 2;
  caras[1]._2 = 4;
  caras[2]._0 = 2;
  caras[2]._1 = 3;
  caras[2]._2 = 4;
  caras[3]._0 = 3;
  caras[3]._1 = 0;
  caras[3]._2 = 4;
  caras[4]._0 = 3;
  caras[4]._1 = 1;
  caras[4]._2 = 0;
  caras[5]._0 = 3;
  caras[5]._1 = 2;
  caras[5]._2 = 1;

  // colores de las caras
  colors_random();
}

//*************************************************************************
// clase objeto ply
//*************************************************************************

_objeto_ply::_objeto_ply()
{
  // leer lista de coordenadas de vértices y lista de indices de vértices
}

void _objeto_ply::parametros(char *archivo)
{
  int i, n_ver, n_car;

  vector<float> ver_ply;
  vector<int> car_ply;

  _file_ply::read(archivo, ver_ply, car_ply);

  n_ver = ver_ply.size() / 3;
  n_car = car_ply.size() / 3;

  printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

  vertices.resize(n_ver);
  caras.resize(n_car);
  // vértices

  for (i = 0; i < n_ver; i++)
  {
    vertices[i].x = ver_ply[3 * i];
    vertices[i].y = ver_ply[3 * i + 1];
    vertices[i].z = ver_ply[3 * i + 2];
  }

  // vértices
  for (i = 0; i < n_car; i++)
  {
    caras[i].x = car_ply[3 * i];
    caras[i].y = car_ply[3 * i + 1];
    caras[i].z = car_ply[3 * i + 2];
  }

  colores_caras.resize(n_car);
  srand(10);
  // colores
  float sum;
  int n;
  colores_caras.resize(caras.size());
  for (i = 0; i < caras.size(); i++)
  {
    if (vertices[caras[i]._0].y >= 0)
    {
      colores_caras[i].r = rand() % 1000 / 1000.0;
      colores_caras[i].b = 0.0;
      colores_caras[i].g = 0.8;
    }
    else
    {
      n = rand() % 10;
      sum = rand() % 100 / 500.0;
      if (n < 5)
        colores_caras[i].r = 0.251 + sum;
      else
        colores_caras[i].r = 0.251 - sum;
      if (n > 5)
        colores_caras[i].b = 0.805 + sum;
      else
        colores_caras[i].b = 0.805 - sum;
      if (n > 5)
        colores_caras[i].g = 0.816 + sum;
      else
        colores_caras[i].g = 0.816 - sum;
    }
  }
}

//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{
}

void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_in, int tapa_su)
{
  int i, j;
  _vertex3f vertice_aux;
  _vertex3i cara_aux;
  int num_aux;
  float radio;

  // tratamiento de los vértice
  radio = sqrt(perfil[0].x * perfil[0].x + perfil[0].y * perfil[0].y);

  num_aux = perfil.size();
  if (tipo == 1)
    num_aux = num_aux - 1;
  vertices.resize(num_aux * num + 2);
  for (j = 0; j < num; j++)
  {
    for (i = 0; i < num_aux; i++)
    {
      vertice_aux.x = perfil[i].x * cos(2.0 * M_PI * j / (1.0 * num)) +
                      perfil[i].z * sin(2.0 * M_PI * j / (1.0 * num));
      vertice_aux.z = -perfil[i].x * sin(2.0 * M_PI * j / (1.0 * num)) +
                      perfil[i].z * cos(2.0 * M_PI * j / (1.0 * num));
      vertice_aux.y = perfil[i].y;
      vertices[i + j * num_aux] = vertice_aux;
    }
  }

  caras.resize(2 * (num_aux - 1) * num + 2 * num);
  int c = 0;
  for (j = 0; j < num; j++)
  {
    for (i = 0; i < num_aux - 1; i++)
    {
      caras[c]._0 = i + j * num_aux;
      caras[c]._1 = ((j + 1) % num) * num_aux + i;
      caras[c]._2 = 1 + i + j * num_aux;
      c += 1;
      caras[c]._0 = ((j + 1) % num) * num_aux + i;
      caras[c]._1 = ((j + 1) % num) * num_aux + 1 + i;
      caras[c]._2 = 1 + i + j * num_aux;
      c += 1;
    }
  }

  // tapa inferior
  int total = num_aux * num;
  vertices[total].x = 0.0;
  if (tipo == 2)
    vertices[total].y = -radio;
  else
    vertices[total].y = perfil[0].y;
  vertices[total].z = 0.0;

  for (j = 0; j < num; j++)
  {
    caras[c]._0 = j * num_aux;
    caras[c]._1 = ((j + 1) % num) * num_aux;
    caras[c]._2 = total;
    c += 1;
  }

  // tapa superior
  vertices[total + 1].x = 0.0;
  if (tipo == 1)
    vertices[total + 1].y = perfil[1].y;
  if (tipo == 0)
    vertices[total + 1].y = perfil[num_aux - 1].y;
  if (tipo == 2)
    vertices[total + 1].y = radio;
  vertices[total + 1].z = 0.0;

  for (j = 0; j < num; j++)
  {
    caras[c]._0 = total + 1;
    caras[c]._1 = ((j + 1) % num) * num_aux + num_aux - 1;
    caras[c]._2 = num_aux - 1 + j * num_aux;
    c += 1;
  }

  // colores de las caras
  colors_random();
}

//************************************************************************
// objeto cilindro (caso especial de rotacion)
//************************************************************************

_cilindro::_cilindro(float radio, float altura, int num)
{
  vector<_vertex3f> perfil;
  _vertex3f aux;

  aux.x = radio;
  aux.y = -altura / 2.0;
  aux.z = 0.0;
  perfil.push_back(aux);
  aux.x = radio;
  aux.y = altura / 2.0;
  aux.z = 0.0;
  perfil.push_back(aux);
  parametros(perfil, num, 0, 1, 1);
}

//************************************************************************
// objeto cono (caso especial de rotacion)
//************************************************************************

_cono::_cono(float radio, float altura, int num)
{
  vector<_vertex3f> perfil;
  _vertex3f aux;

  aux.x = radio;
  aux.y = 0;
  aux.z = 0.0;
  perfil.push_back(aux);
  aux.x = 0.0;
  aux.y = altura;
  aux.z = 0.0;
  perfil.push_back(aux);
  parametros(perfil, num, 1, 1, 1);
}

//************************************************************************
// objeto esfera (caso especial de rotacion)
//************************************************************************

_esfera::_esfera(float radio, int num1, int num2)
{
  vector<_vertex3f> perfil;
  _vertex3f aux;
  int i;
  for (i = 1; i < num1; i++)
  {
    aux.x = radio * cos(M_PI * i / (num1 * 1.0) - M_PI / 2.0);
    aux.y = radio * sin(M_PI * i / (num1 * 1.0) - M_PI / 2.0);
    aux.z = 0.0;
    perfil.push_back(aux);
  }
  parametros(perfil, num2, 2, 1, 1);
}

//************************************************************************
// rotacion archivo PLY (caso especial de rotacion)
//************************************************************************

_rotacion_PLY::_rotacion_PLY()
{
}

void _rotacion_PLY::parametros_PLY(char *archivo, int num)
{
}

//************************************************************************

//************************************************************************
// objeto por extrusión
//************************************************************************

_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z)
{
  int i;
  _vertex3f vertice_aux;
  _vertex3i cara_aux;
  int num_aux;

  // tratamiento de los vértice

  num_aux = poligono.size();
  vertices.resize(num_aux * 2);
  for (i = 0; i < num_aux; i++)
  {
    vertices[2 * i] = poligono[i];
    vertices[2 * i + 1].x = poligono[i].x + x;
    vertices[2 * i + 1].y = poligono[i].y + y;
    vertices[2 * i + 1].z = poligono[i].z + z;
  }

  // tratamiento de las caras

  caras.resize(num_aux * 2);
  int c = 0;
  for (i = 0; i < num_aux; i++)
  {
    caras[c]._0 = i * 2;
    caras[c]._1 = (i * 2 + 2) % (num_aux * 2);
    caras[c]._2 = i * 2 + 1;
    c = c + 1;
    caras[c]._0 = (i * 2 + 2) % (num_aux * 2);
    caras[c]._1 = (i * 2 + 2) % (num_aux * 2) + 1;
    caras[c]._2 = i * 2 + 1;
    c = c + 1;
  }

  // colores de las caras
  colors_random();
}

//************************************************************************
// práctica 3, objeto jerárquico articulado
//************************************************************************

//************************************************************************
// piezas
//************************************************************************

//************************************************************************
// pala
//************************************************************************

_pala::_pala(float radio, float ancho, int num)
{
  vector<_vertex3f> perfil;
  _vertex3f vertice_aux;
  _vertex3i cara_aux;
  int i, j;

  vertice_aux.x = radio;
  vertice_aux.y = 0;
  vertice_aux.z = -ancho / 2.0;
  perfil.push_back(vertice_aux);
  vertice_aux.z = ancho / 2.0;
  perfil.push_back(vertice_aux);

  // tratamiento de los vértices

  for (j = 0; j <= num; j++)
  {
    for (i = 0; i < 2; i++)
    {
      vertice_aux.x = perfil[i].x * cos(M_PI * j / (1.0 * num)) -
                      perfil[i].y * sin(M_PI * j / (1.0 * num));
      vertice_aux.y = perfil[i].x * sin(M_PI * j / (1.0 * num)) +
                      perfil[i].y * cos(M_PI * j / (1.0 * num));
      vertice_aux.z = perfil[i].z;
      vertices.push_back(vertice_aux);
    }
  }

  // tratamiento de las caras

  for (j = 0; j < num; j++)
  {
    cara_aux._0 = j * 2;
    cara_aux._1 = (j + 1) * 2;
    cara_aux._2 = (j + 1) * 2 + 1;
    caras.push_back(cara_aux);

    cara_aux._0 = j * 2;
    cara_aux._1 = (j + 1) * 2 + 1;
    cara_aux._2 = j * 2 + 1;
    caras.push_back(cara_aux);
  }

  // tapa inferior
  vertice_aux.x = 0;
  vertice_aux.y = 0;
  vertice_aux.z = -ancho / 2.0;
  vertices.push_back(vertice_aux);

  for (j = 0; j < num; j++)
  {
    cara_aux._0 = j * 2;
    cara_aux._1 = (j + 1) * 2;
    cara_aux._2 = vertices.size() - 1;
    caras.push_back(cara_aux);
  }

  // tapa superior
  vertice_aux.x = 0;
  vertice_aux.y = 0;
  vertice_aux.z = ancho / 2.0;
  vertices.push_back(vertice_aux);

  for (j = 0; j < num; j++)
  {
    cara_aux._0 = j * 2 + 1;
    cara_aux._1 = (j + 1) * 2 + 1;
    cara_aux._2 = vertices.size() - 1;
    caras.push_back(cara_aux);
  }

  colors_chess(1.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}

//************************************************************************
// brazo
//************************************************************************

_brazo::_brazo()
{
  ancho = 0.6;
  alto = 0.1;
  fondo = 0.1;
  colors_chess(1.0, 1.0, 0.0, 0.0, 0.0, 1.0);
};

void _brazo::draw(_modo modo, float r, float g, float b, float grosor)
{
  glPushMatrix();
  glScalef(ancho, alto, fondo);
  glTranslatef(0.5, 0, 0);
  cubo.draw(modo, r, g, b, grosor);
  glPopMatrix();
};

//************************************************************************
// cabina
//************************************************************************

_cabina::_cabina()
{
  ancho = 0.4;
  alto = 0.6;
  fondo = 0.4;
  cubo.colors_chess(1.0, 1.0, 0.0, 0.0, 0.0, 1.0);
};

void _cabina::draw(_modo modo, float r, float g, float b, float grosor)
{
  glPushMatrix();
  glScalef(ancho, alto, fondo);
  cubo.draw(modo, r, g, b, grosor);
  glPopMatrix();
};

//************************************************************************
// sustentación
//************************************************************************

_sustentacion::_sustentacion()
{
  ancho = 1.2;
  alto = 0.3;
  fondo = 0.8;
  radio = 0.15;
  base.colors_chess(1.0, 1.0, 0.0, 0.0, 0.0, 1.0);
};

void _sustentacion::draw(_modo modo, float r, float g, float b, float grosor)
{
  glPushMatrix();
  glTranslatef(2 * ancho / 6, -alto / 2.0, 0);
  glRotatef(90, 1, 0, 0);
  glScalef(radio, fondo / 2.2, radio);
  rueda.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2 * ancho / 6, -alto / 2.0, 0);
  glRotatef(90, 1, 0, 0);
  glScalef(radio, fondo / 2.2, radio);
  rueda.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glScalef(ancho, alto, fondo);
  base.draw(modo, r, g, b, grosor);
  glPopMatrix();
};

//************************************************************************
// excavadora (montaje del objeto final)
//************************************************************************

_excavadora::_excavadora()
{
  giro_cabina = 0.0;
  giro_primer_brazo = 0.0;
  giro_primer_brazo_max = 0;
  giro_primer_brazo_min = -90;
  giro_segundo_brazo = 0.0;
  giro_segundo_brazo_max = 30;
  giro_segundo_brazo_min = 0;
  giro_pala = 0.0;
  giro_pala_max = 50.0;
  giro_pala_min = -90.0;

  tamanio_pala = 0.15;
};

void _excavadora::draw(_modo modo, float r, float g, float b, float grosor)
{
  glPushMatrix();

  sustentacion.draw(modo, r, g, b, grosor);

  glTranslatef(0, (cabina.alto + sustentacion.alto) / 2.0, 0);
  glRotatef(giro_cabina, 0, 1, 0);
  cabina.draw(modo, r, g, b, grosor);

  glTranslatef(cabina.ancho / 2.0, 0, 0);
  glRotatef(giro_segundo_brazo, 0, 0, 1);
  brazo.draw(modo, r, g, b, grosor);

  glTranslatef(brazo.ancho, 0, 0);
  glRotatef(giro_primer_brazo, 0, 0, 1);
  brazo.draw(modo, r, g, b, grosor);

  glTranslatef(brazo.ancho, 0, 0);
  glRotatef(giro_pala, 0, 0, 1);
  glTranslatef(tamanio_pala, 0, 0);
  glScalef(tamanio_pala, tamanio_pala, tamanio_pala);
  pala.draw(modo, r, g, b, grosor);

  glPopMatrix();
};

//************************************************************************
// Plataforma scooter
//************************************************************************

_plataforma::_plataforma()
{
  ancho = 3;
  alto = 0.7;
  fondo = 0.1;
};

void _plataforma::draw(_modo modo, float r, float g, float b, float grosor)
{
  glPushMatrix();

  // plataforma_base__fino
  glPushMatrix();
  glTranslatef(0, -1.5, 0);
  glRotatef(90, 1, 0, 0);
  glScalef(ancho, alto, fondo);
  if (modo == 4)
    plataforma_base.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    plataforma_base.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(ancho / 2, -1.5, 0);
  glScaled(alto / 2, fondo / 2, alto / 2);
  if (modo == 4)
    base.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    base.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-ancho / 2, -1.5, 0);
  glScaled(alto / 2, fondo / 2, alto / 2);
  if (modo == 4)
    base.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    base.draw(modo, r, g, b, grosor);
  glPopMatrix();

  // plataforma_base_beteria
  glPushMatrix();
  glTranslatef(0, -1.7, 0);
  glRotatef(90, 1, 0, 0);
  glScalef(ancho + 0.2, alto - 0.2, 0.3);
  if (modo == 4)
    plataforma_base.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    plataforma_base.draw(modo, r, g, b, grosor);
  glPopMatrix();

  // cilintro conecta parte delantera
  glPushMatrix();
  glTranslatef(-ancho / 2 - 0.3, -1.2, 0);
  glRotatef(45, 0, 0, 1);
  glScaled(0.1, 0.6, 0.1);
  if (modo == 4)
    conecta_rueda.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    conecta_rueda.draw(modo, r, g, b, grosor);
  glPopMatrix();

  // enlaces conecta rudas
  glPushMatrix();
  glTranslatef(ancho / 2 + 0.4, -1.7, +alto / 2 - 0.1);
  glScalef(0.9, 0.1, 0.1);
  if (modo == 4)
    plataforma_base.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    plataforma_base.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(ancho / 2 + 0.4, -1.7, +alto / 2);
  glScalef(0.2, 0.1, 0.1);
  if (modo == 4)
    plataforma_base.draw(modo, 1, 0.5f, 0, grosor);
  else
    plataforma_base.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(ancho / 2 + 0.4, -1.7, -alto / 2 + 0.1);
  glScalef(0.9, 0.1, 0.1);
  if (modo == 4)
    plataforma_base.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    plataforma_base.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(ancho / 2 + 0.4, -1.7, -alto / 2);
  glScalef(0.2, 0.1, 0.1);
  if (modo == 4)
    plataforma_base.draw(modo, 1, 0.5f, 0, grosor);
  else
    plataforma_base.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPopMatrix();
};

//************************************************************************
// scooter (montaje del objeto final)
//************************************************************************
_scooter::_scooter()
{
  tam = 0;
  alto = 1.5;
  radio = 0.1;

  avanzar = 0;
  retroceder = 0;
  giro_rueda_delantero = 0;
  giro_rueda_trasera = 0;
  giro_freno_1 = 0;
  giro_freno_1_max = 75;
  giro_freno_1_min = 0;
  giro_freno_2 = 0;
  giro_freno_2_max = 30;
  giro_freno_2_min = 0;
  giro_manilla = 0;
  giro_manilla_max = 35;
  giro_manilla_min = -35;
  giro_conecta_manilla = 0;
  giro_conecta_manilla_max = 0;
  giro_conecta_manilla_min = -92;
}
void _scooter::draw(_modo modo, float r, float g, float b, float grosor)
{
  glPushMatrix(); // scooter
  // glTranslatef(avanzar, -1.7, 0);

  // plataforma + rueda trasela
  glPushMatrix();
  plataforma.draw(modo, r, g, b, grosor);
  glTranslatef(plataforma.ancho / 2 + 0.8, -1.7, 0);
  glRotatef(90, 1, 0, 0);
  glRotated(giro_rueda_trasera, 0, 1, 0);
  glScalef(0.5, plataforma.alto / 2 - 0.15, 0.5);
  if (modo == 4)
    rueda.draw(modo, 0, 0, 0, grosor);
  else
    rueda.draw(modo, r, g, b, grosor);
  glPopMatrix(); // fin plataforma + rueda trasela

  // freno de pie
  glPushMatrix();
  glTranslatef(plataforma.ancho / 2 - 0.4, -1.8, +plataforma.alto / 2 - 0.05);
  glTranslatef(0, 0.2, 0);
  glRotatef(giro_freno_1, 0, 0, 1);
  glTranslatef(0, -0.2, 0);
  glRotatef(-23, 1, 0, 0);
  glScalef(0.05, plataforma.alto / 2, 0.05);
  if (modo == 4)
    freno.draw(modo, 0.3f, 0.3f, 0.3f, grosor);
  else
    freno.draw(modo, r, g, b, grosor);
  glPopMatrix(); // fin freno pied

  // Conjunto de manillas + contacta rueda delantela
  glPushMatrix();

  glPushMatrix();
  // rotacion para plegar scooter
  glTranslatef(-2.255, -0.65, 0);
  glRotatef(giro_conecta_manilla, 0, 0, 1);
  glTranslatef(2.25, 0.7, 0);

  glPushMatrix(); // rotacion de conjunto de manilla
  glTranslatef(-1.6, -1.4, 0);
  glRotated(giro_manilla, 0, 1, 0);
  glTranslatef(1.6, 1.4, 0);
  // manilla
  glPushMatrix();
  glTranslatef(-3 / 2 - 0.75, alto * 2 + 0.1, 0);
  glRotatef(90, 1, 0, 0);
  glScalef(radio, alto, radio);
  if (modo == 4)
    manilla.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    manilla.draw(modo, r, g, b, grosor);
  glPopMatrix();
  // freno de mano
  glPushMatrix();
  glTranslatef(-2, alto * 2 + 0.15, -0.5);
  glRotatef(90, 1, 0, 0);
  glRotatef(-45, 0, 0, 1);
  glTranslatef(0, 0.3, 0);
  glRotatef(giro_freno_2, 0, 0, 1);
  glTranslatef(0, -0.3, 0);
  glScalef(0.05, plataforma.alto / 2, 0.05);
  if (modo == 4)
    freno.draw(modo, 0.3f, 0.3f, 0.3f, grosor);
  else
    freno.draw(modo, r, g, b, grosor);
  glPopMatrix();
  glPopMatrix(); // fin rotacion de conjunto de minilla

  // palo largo que conecta manilla y ruda
  glPushMatrix();
  glTranslatef(-3 / 2 - 1, alto - 0.3, 0);
  glRotatef(-8, 0, 0, 1);
  glRotated(giro_manilla, 0, 1, 0);
  glScalef(radio, alto + 0.455, radio);
  if (modo == 4)
    conecta_rueda_minilla.draw(modo, 0.3f, 0.3f, 0.3f, grosor);
  else
    conecta_rueda_minilla.draw(modo, r, g, b, grosor);
  glPopMatrix();
  glPopMatrix(); // fin rotacion para plegar scooter

  // rotacion conjunto de conecta rueda delantera
  glPushMatrix();
  glTranslatef(-2.3, -0.89, 0);
  glRotated(giro_manilla, 0, 1, 0);
  glTranslatef(2.3, 0.89, 0);
  glPushMatrix();
  glTranslatef(-2.3, -0.89, 0);
  glRotatef(-8, 0, 0, 1);
  glScalef(radio + 0.2, plataforma.alto / 2 - 0.15, radio + 0.2);
  if (modo == 4)
    conecta_rueda_minilla.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    conecta_rueda_minilla.draw(modo, r, g, b, grosor);
  glTranslated(0, -1.65, 0.75);
  glScaled(0.2, 5, 0.2);
  if (modo == 4)
    conecta_rueda.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    conecta_rueda.draw(modo, r, g, b, grosor);
  glTranslated(0, 0, -7.5);
  if (modo == 4)
    conecta_rueda.draw(modo, 0.5f, 0.5f, 0.5f, grosor);
  else
    conecta_rueda.draw(modo, r, g, b, grosor);
  glPopMatrix();
  // rueda delantero
  glPushMatrix();
  glTranslatef(-plataforma.ancho / 2 - 0.9, -1.7, 0);
  glRotatef(90, 1, 0, 0);
  glRotated(giro_rueda_delantero, 0, 1, 0);
  glScalef(0.5, plataforma.alto / 2 - 0.15, 0.5);
  if (modo == 4)
    rueda.draw(modo, 0, 0, 0, grosor);
  else
    rueda.draw(modo, r, g, b, grosor);
  glPopMatrix(); // fin rueda delantera
  glPopMatrix(); // fin rotacion conjunto de conecta rueda trasera

  glPopMatrix(); // fin conjunto

  glPopMatrix(); // fin scooter
};

//************************************************************************
// ejercicio1
//************************************************************************
_ejercicio1::_ejercicio1(float largo, float ancho, float al)
{
  int i;
  // vertices
  vertices.resize(6);
  vertices[0].x = -ancho;
  vertices[0].y = 0;
  vertices[0].z = largo;
  vertices[1].x = ancho;
  vertices[1].y = 0;
  vertices[1].z = largo;
  vertices[2].x = ancho;
  vertices[2].y = 0;
  vertices[2].z = -largo;
  vertices[3].x = -ancho;
  vertices[3].y = 0;
  vertices[3].z = -largo;
  vertices[4].x = 0;
  vertices[4].y = al;
  vertices[4].z = 0;
  vertices[5].x = 0;
  vertices[5].y = -al;
  vertices[5].z = 0;

  caras.resize(6);
  caras[0]._0 = 0;
  caras[0]._1 = 1;
  caras[0]._2 = 4;
  caras[1]._0 = 1;
  caras[1]._1 = 2;
  caras[1]._2 = 4;
  caras[2]._0 = 2;
  caras[2]._1 = 3;
  caras[2]._2 = 4;
  caras[3]._0 = 3;
  caras[3]._1 = 0;
  caras[3]._2 = 4;
  caras[4]._0 = 5;
  caras[4]._1 = 0;
  caras[4]._2 = 1;
  caras[5]._0 = 5;
  caras[5]._1 = 2;
  caras[5]._2 = 3;
}

//************************************************************************
// ejercicio2
//************************************************************************
_ejercicio2::_ejercicio2(float radio, int num1, int num2)
{
  vector<_vertex3f> perfil;
  _vertex3f aux;
  int i;

  aux.x = 0;
  aux.y = 0;
  aux.z = 0;
  perfil.push_back(aux);
  aux.x = 0.8;
  aux.y = 0;
  aux.z = 0;
  perfil.push_back(aux);
  aux.x = 0.4;
  aux.y = 0.4;
  aux.z = 0;
  perfil.push_back(aux);

  for (i = 0; i < num1-1; i++)
  {
    aux.x = radio * cos(M_PI * i / (num1 * 1.0) - M_PI / 2.0)+1.4;
    aux.y = radio * sin(M_PI * i / (num1 * 1.0) - M_PI / 2.0)+1.8;
    aux.z = 0.0;
    perfil.push_back(aux);
  }
  

  parametros(perfil, num2, 2, 1, 1);
}

//************************************************************************
// ejercicio3
//************************************************************************

_ejercicio3::_ejercicio3()
{
  alto = 1;
  radio = 0.2;
  giro_cono = 0;
  giro_cilindro = 0.6;
  a = 0.6;
  num1 = 2;
  num2 = 6;
  ancho = 2;
}

void _ejercicio3::draw(_modo modo, float r, float g, float b, float grosor)
{
  glPushMatrix();

  glTranslatef(a, 0, 0);
  glRotated(giro_cono, 0, 1, 0);
  glTranslatef(-a, 0, 0);
  
  glPushMatrix();
  glTranslatef(a, 0, 0);
  glScalef(radio * 2, (alto / 2) - 0.05, radio * 2);
  cono.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(ancho / 2, alto, 0);
  glRotated(180, 1, 0, 0);
  glScalef(ancho, 0.2, 0.5);
  cubo.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(ancho - radio, giro_cilindro + alto + radio / 2, 0);
  glScalef(radio, giro_cilindro, radio);
  cilindro.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(ancho - radio, giro_cilindro * 2 + alto + radio / 2 + radio * 2, 0);
  glScalef(radio * 2, radio * 2, radio * 2);
  esfera.draw(modo, r, g, b, grosor);
  glPopMatrix();

  glPopMatrix();
}