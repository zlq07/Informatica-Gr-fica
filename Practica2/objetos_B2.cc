//**************************************************************************
// Práctica 2
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"

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
  int i;
  glPointSize(grosor);
  glColor3f(r, g, b);
  glBegin(GL_POINTS);
  for (i = 0; i < vertices.size(); i++)
  {
    glVertex3fv((GLfloat *)&vertices[i]);
  }
  glEnd();
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
  int i;
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glLineWidth(grosor);
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
  }
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
  // vertices
  vertices.resize(8);
  vertices[0].x = -tam / 2;
  vertices[0].y = -tam / 2;
  vertices[0].z = -tam / 2;
  vertices[1].x = tam / 2;
  vertices[1].y = -tam / 2;
  vertices[1].z = -tam / 2;
  vertices[2].x = tam / 2;
  vertices[2].y = -tam / 2;
  vertices[2].z = tam / 2;
  vertices[3].x = -tam / 2;
  vertices[3].y = -tam / 2;
  vertices[3].z = tam / 2;
  vertices[4].x = -tam / 2;
  vertices[4].y = tam / 2;
  vertices[4].z = -tam / 2;
  vertices[5].x = tam / 2;
  vertices[5].y = tam / 2;
  vertices[5].z = -tam / 2;
  vertices[6].x = tam / 2;
  vertices[6].y = tam / 2;
  vertices[6].z = tam / 2;
  vertices[7].x = -tam / 2;
  vertices[7].y = tam / 2;
  vertices[7].z = tam / 2;

  // triangulos
  caras.resize(12);
  caras[0]._0 = 0;
  caras[0]._1 = 1;
  caras[0]._2 = 4;
  caras[1]._0 = 1;
  caras[1]._1 = 5;
  caras[1]._2 = 4;
  caras[2]._0 = 1;
  caras[2]._1 = 2;
  caras[2]._2 = 5;
  caras[3]._0 = 2;
  caras[3]._1 = 6;
  caras[3]._2 = 5;
  caras[4]._0 = 2;
  caras[4]._1 = 3;
  caras[4]._2 = 6;
  caras[5]._0 = 3;
  caras[5]._1 = 7;
  caras[5]._2 = 6;
  caras[6]._0 = 3;
  caras[6]._1 = 0;
  caras[6]._2 = 7;
  caras[7]._0 = 0;
  caras[7]._1 = 4;
  caras[7]._2 = 7;
  caras[8]._0 = 4;
  caras[8]._1 = 5;
  caras[8]._2 = 6;
  caras[9]._0 = 4;
  caras[9]._1 = 6;
  caras[9]._2 = 7;
  caras[10]._0 = 3;
  caras[10]._1 = 1;
  caras[10]._2 = 0;
  caras[11]._0 = 3;
  caras[11]._1 = 2;
  caras[11]._2 = 1;

  // colores
  colores_caras.resize(12);
  /*  float ini = 0.0;
    for (int i = 0; i < 12; i++)
    {
      colores_caras[i].r = ini;
      colores_caras[i].g = ini;
      colores_caras[i].b = ini;
      ini += 10;
    }
  */
  colores_caras[0].r = 1.0;
  colores_caras[0].g = 0.0;
  colores_caras[0].b = 0.0;
  // color verde
  colores_caras[1].r = 0.0;
  colores_caras[1].g = 1.0;
  colores_caras[1].b = 0.0;
  // color armarillo
  colores_caras[2].r = 1.0;
  colores_caras[2].g = 1.0;
  colores_caras[2].b = 0.0;
  // color azul
  colores_caras[3].r = 0.0;
  colores_caras[3].g = 0.0;
  colores_caras[3].b = 1.0;
  // color rojo
  colores_caras[4].r = 1.0;
  colores_caras[4].g = 0.0;
  colores_caras[4].b = 1.0;
  // color
  colores_caras[5].r = 0.0;
  colores_caras[5].g = 0.0;
  colores_caras[5].b = 0.0;

  colores_caras[6].r = (double)1.3;
  colores_caras[6].g = (double)0.3;
  colores_caras[6].b = (double)0.3;

  colores_caras[7].r = (double)0.3;
  colores_caras[7].g = (double)1.3;
  colores_caras[7].b = (double)0.3;

  colores_caras[8].r = (double)1.3;
  colores_caras[8].g = (double)1.3;
  colores_caras[8].b = (double)0.3;

  colores_caras[9].r = (double)0.3;
  colores_caras[9].g = (double)0.3;
  colores_caras[9].b = (double)1.3;

  colores_caras[10].r = (double)1.3;
  colores_caras[10].g = (double)0.3;
  colores_caras[10].b = (double)1.3;

  colores_caras[11].r = (double)1.3;
  colores_caras[11].g = (double)1.3;
  colores_caras[11].b = (double)1.3;

  colores_caras[12].r = (double)0.3;
  colores_caras[12].g = (double)0.3;
  colores_caras[12].b = (double)0.3;
}

//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

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

  colores_caras.resize(6);
  // color rojo
  colores_caras[0].r = 1.0;
  colores_caras[0].g = 0.0;
  colores_caras[0].b = 0.0;
  // color verde
  colores_caras[1].r = 0.0;
  colores_caras[1].g = 1.0;
  colores_caras[1].b = 0.0;
  // color armarillo
  colores_caras[2].r = 1.0;
  colores_caras[2].g = 1.0;
  colores_caras[2].b = 0.0;
  // color azul
  colores_caras[3].r = 0.0;
  colores_caras[3].g = 0.0;
  colores_caras[3].b = 1.0;
  // color rojo
  colores_caras[4].r = 1.0;
  colores_caras[4].g = 0.0;
  colores_caras[4].b = 1.0;
  // color
  colores_caras[5].r = 0.0;
  colores_caras[5].g = 0.0;
  colores_caras[5].b = 0.0;
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
  int n_ver, n_car;

  vector<float> ver_ply;
  vector<int> car_ply;

  _file_ply::read(archivo, ver_ply, car_ply);

  n_ver = ver_ply.size() / 3;
  n_car = car_ply.size() / 3;

  printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

  vertices.resize(n_ver);
  caras.resize(n_car);
  int i;
  for (i = 0; i < vertices.size(); i++)
  {
    vertices[i].x = ver_ply[3 * i];
    vertices[i].y = ver_ply[3 * i + 1];
    vertices[i].z = ver_ply[3 * i + 2];
  }

  for (i = 0; i < caras.size(); i++)
  {
    caras[i]._0 = car_ply[3 * i];
    caras[i]._1 = car_ply[3 * i + 1];
    caras[i]._2 = car_ply[3 * i + 2];
  }

  colores_caras.resize(n_car);
  int n;
  float sum;
  for (int i = 0; i < caras.size(); i++)
  {
    /*if (vertices[caras[i]._0].y >= 0)
    {
      colores_caras[i].r = rand() % 1000 / 1000.0;
      colores_caras[i].g = 0;
      colores_caras[i].b = 0.8;
    }*/
    // else
    //{
    n = rand() % 10;
    sum = rand() % 100 / 100.0;
    if (n < 5)
      colores_caras[i].r = 0.251 + sum;
    else
      colores_caras[i].r = 0.251 - sum;

    if (n = 5)
      colores_caras[i].b = 0.705 + sum;
    else
      colores_caras[i].b = 0.705 - sum;

    if (n > 5)
      colores_caras[i].g = 0.816 + sum;
    else
      colores_caras[i].g = 0.816 - sum;
    //}
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
  int radio;

  // tratamiento de los vértice
  // pagina 54 de diapositiva tema2

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

  int c = 0;
  // tratamiento de las caras
  caras.resize(2 * (num_aux - 1) * num + 2 * num);
  for (j = 0; j < num; j++)
  {
    for (i = 0; i < num_aux - 1; i++)
    {
      caras[c]._0 = i + j * num_aux;
      caras[c]._1 = ((j + 1) % num) * num_aux + i;
      caras[c]._2 = i + 1 + j * num_aux;
      c = c + 1;
      caras[c]._0 = ((j + 1) % num) * num_aux + i;
      caras[c]._1 = ((j + 1) % num) * num_aux + i + 1;
      caras[c]._2 = i + 1 + j * num_aux;
      c = c + 1;
    }
  }

  radio = sqrt(perfil[0].x * perfil[0].x+perfil[0].y * perfil[0].y);
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
    c = c + 1;
  }

  // tapa superior

  vertices[total + 1].x = 0.0;
  if (tipo == 0)
    vertices[total + 1].y = perfil[num_aux - 1].y;
  if (tipo == 1)
    vertices[total + 1].y = perfil[1].y;
  if (tipo == 2)
    vertices[total + 1].y = radio;
  vertices[total + 1].z = 0.0;
  for (j = 0; j < num; j++)
  {
    caras[c]._0 = total + 1;
    caras[c]._1 = ((j + 1) % num) * num_aux + num_aux - 1;
    caras[c]._2 = j * num_aux + num_aux - 1;
    c = c + 1;
  }

  colores_caras.resize(2 * (num_aux - 1) * num + 2 * num);
  int n;
  float sum;
  for (int i = 0; i < caras.size(); i++)
  {
    /*if (vertices[caras[i]._0].y >= 0)
    {
      colores_caras[i].r = rand() % 1000 / 1000.0;
      colores_caras[i].g = 0;
      colores_caras[i].b = 0.8;
    }*/
    // else
    //{
    n = rand() % 10;
    sum = rand() % 100 / 100.0;
    if (n < 5)
      colores_caras[i].r = 0.251 + sum;
    else
      colores_caras[i].r = 0.251 - sum;

    if (n == 5)
      colores_caras[i].b = 0.705 + sum;
    else
      colores_caras[i].b = 0.705 - sum;

    if (n > 5)
      colores_caras[i].g = 0.816 + sum;
    else
      colores_caras[i].g = 0.816 - sum;
    //}
  }
}

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
}

//************************************************************************
// Clase cono
//************************************************************************
_cono::_cono(float radio, float altura, int num)
{
  vector<_vertex3f> perfil_cono;
  _vertex3f aux_cono;
  aux_cono.x = 0.0;
  aux_cono.y = altura;
  aux_cono.z = 0.0;
  perfil_cono.push_back(aux_cono);
  aux_cono.x = radio;
  aux_cono.y = 0.0;
  aux_cono.z = 0.0;
  perfil_cono.push_back(aux_cono);

  parametros(perfil_cono, num, 1, 1, 1);
}

//************************************************************************
// Clase cilindro
//************************************************************************
_cilindro::_cilindro(float radio, float altura, int num)
{
  vector<_vertex3f> perfil_cilindro;
  _vertex3f aux_cilindro;

  aux_cilindro.x = radio;
  aux_cilindro.y = -altura / 2;
  aux_cilindro.z = 0.0;
  perfil_cilindro.push_back(aux_cilindro);
  aux_cilindro.x = radio;
  aux_cilindro.y = altura / 2;
  aux_cilindro.z = 0.0;
  perfil_cilindro.push_back(aux_cilindro);

  parametros(perfil_cilindro, num, 0, 1, 1);
}

//************************************************************************
// Clase esfera
// num2 lados
// num1
//************************************************************************
_esfera::_esfera(float radio, int num1, int num2)
{
  vector<_vertex3f> perfil_esfera;
  _vertex3f aux_esfera;
  for (int i = 1; i < num1; i++)
  {
    aux_esfera.x = cos(M_PI * i / (num1 * 1.0) - M_PI / 2.0);
    aux_esfera.y = sin(M_PI * i / (num1 * 1.0) - M_PI / 2.0);
    aux_esfera.z = 0.0;
    perfil_esfera.push_back(aux_esfera);
  }

  parametros(perfil_esfera, num1, 2, 1, 1);
}
