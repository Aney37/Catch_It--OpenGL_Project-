#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <ctime>
using namespace std;


int w, h,temp=0,i=0,mouse_click=0,click_x,click_y,press=0,miss_object=0;
const int font=(int)GLUT_BITMAP_9_BY_15;
char s[30];

double t;//x=5.5,y=-5.5;

double object_x[] = {-5.5,-5.5,-5.5,-5.5,-5.5,-5.5,-5.5,-5.5};

double object_y[] = {1,0,-1,-2,-3,-4,-5,-6};

double starting_y[] = {1,0,-1,-2,-3,-4,-5,-6};
double speed[] = {0.002,0.001,0.01,0.008,0.002,0.002,0.004,0.008};
int num_boxes = 8;


double fr_x1=0.5,fr_x2=-0.5,fr_y1=0.5,fr_y2=0.5;
string score;
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    w = width;
    h = height;
    glViewport(0, 0, width, height);
}
void setOrthographicProjection() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
       gluOrtho2D(0, w, 0, h);
    glScalef(1, -1, 1);
    glTranslatef(0, -h, 0);
    glMatrixMode(GL_MODELVIEW);
}
void resetPerspectiveProjection() {
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void IntToChar(int number)
{
    stringstream ss;
    ss << number;
    string str = ss.str();
    glColor3d(1.0, 0.0, 0.0);
    setOrthographicProjection();
    glPushMatrix();
    glLoadIdentity();
    const char* c_score = str.c_str();
    renderBitmapString(300,250,(void *)font,"Score");
    renderBitmapString(380,250,(void *)font,c_score);
    glPopMatrix();

}


void draw_cube(GLfloat size)
{
    float x1,y1,z1;
    float x2,y2,z2;
    float x3,y3,z3;
    float x4,y4,z4;

    x1 = -size/2;
    y1 = -size/2;
    z1 = -size/2;

    x2 = size/2;
    y2 = -size/2;
    z2 = -size/2;

    x3 = size/2;
    y3 = -size/2;
    z3 = size/2;

    x4 = -size/2;
    y4 = -size/2;
    z4 = size/2;

    float x5,y5,z5;
    float x6,y6,z6;
    float x7,y7,z7;
    float x8,y8,z8;

    x5 = -size/2;
    y5 = size/2;
    z5 = -size/2;

    x6 = size/2;
    y6 = size/2;
    z6 = -size/2;

    x7 = size/2;
    y7 = size/2;
    z7 = size/2;

    x8 = -size/2;
    y8 = size/2;
    z8 = size/2;

    float n1_x = 0, n1_y = -1, n1_z = 0; //face that faces towards bottom
    float n2_x = 0, n2_y = 1, n2_z = 0; //up
    float n3_x = 0, n3_y = 0, n3_z = -1; //front
    float n4_x = 0, n4_y = 0, n4_z = 1; //back
    float n5_x = 1, n5_y = 0, n5_z = 0; //right
    float n6_x = -1, n6_y = 0, n6_z = 0; //left

    glBegin(GL_QUADS);
    //Quad 1

    glNormal3f(n1_x,n1_y,n1_z);

    glTexCoord2f(0,0);
    glVertex3f(x1,y1,z1);

    glTexCoord2f(1,0);
    glVertex3f(x2,y2,z2);

    glTexCoord2f(1,1);
    glVertex3f(x3,y3,z3);

    glTexCoord2f(0,1);
    glVertex3f(x4,y4,z4);

    //Quad 2

    glNormal3f(n2_x,n2_y,n2_z);

    glTexCoord2f(0,0);
    glVertex3f(x8,y8,z8);

    glTexCoord2f(1,0);
    glVertex3f(x7,y7,z7);

    glTexCoord2f(1,1);
    glVertex3f(x6,y6,z6);

    glTexCoord2f(0,1);
    glVertex3f(x5,y5,z5);
    //Quad 3

    glNormal3f(n3_x,n3_y,n3_z);

    glTexCoord2f(0,0);
    glVertex3f(x5,y5,z5);

    glTexCoord2f(1,0);
    glVertex3f(x6,y6,z6);

    glTexCoord2f(1,1);
    glVertex3f(x2,y2,z2);

    glTexCoord2f(0,1);
    glVertex3f(x1,y1,z1);
    //Quad 4


    glNormal3f(n4_x,n4_y,n4_z);

    glTexCoord2f(0,0);
    glVertex3f(x7,y7,z7);

    glTexCoord2f(1,0);
    glVertex3f(x8,y8,z8);

    glTexCoord2f(1,1);
    glVertex3f(x4,y4,z4);

    glTexCoord2f(0,1);
    glVertex3f(x3,y3,z3);
    //Quad 5

    glNormal3f(n5_x,n5_y,n5_z);

    glTexCoord2f(0,0);
    glVertex3f(x6,y6,z6);

    glTexCoord2f(1,0);
    glVertex3f(x7,y7,z7);

    glTexCoord2f(1,1);
    glVertex3f(x3,y3,z3);

    glTexCoord2f(0,1);
    glVertex3f(x2,y2,z2);

    //Quad 6

    glNormal3f(n6_x,n6_y,n6_z);

    glTexCoord2f(0,0);
    glVertex3f(x1,y1,z1);

    glTexCoord2f(1,0);
    glVertex3f(x4,y4,z4);

    glTexCoord2f(1,1);
    glVertex3f(x8,y8,z8);

    glTexCoord2f(0,1);
    glVertex3f(x5,y5,z5);


    glEnd();
}

struct Image
{
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};

GLuint texture[10];

int ImageLoad(char *filename, Image *image)
{
    FILE *file;
    unsigned long size; //size of the image in bytes
    unsigned long i; //standard counter
    unsigned short int planes; //number of planes in Image(must be 1)
    unsigned short int bpp; //number of bits per pixel(must be 24)
    char temp; //temporary color storage for bgr-rgb conversion

    //make sure the file in here
    file = fopen(filename, "rb");
    if(file==NULL)
    {
        printf("Can't open file!");
    }

   //seek through the bmp header, up to width/height
    fseek(file,18,SEEK_CUR);

    //read the width
    i = fread(&image->sizeX,4,1,file);
    //read the height
    i = fread(&image->sizeY,4,1,file);
    //calculate the size (assuming 24 bits or 3 bytes per pixel)
    size = image->sizeX * image->sizeY * 3;
    //read the plane
    fread(&planes, 2, 1, file);
    //read the bits per pixel
    fseek(file, 24, SEEK_CUR);
    //read the data
    image->data = (char*)malloc(size);

    i=fread(image->data, size, 1, file);

    for(i=0;i<size;i+=3) //reverse all ol color bgr -> rgb
    {
        temp = image->data[i];
        image->data[i] = image->data[i+1];
        image->data[i+1] = temp;

    }

    fclose(file);
return 1;

}

void loadTexture(char* file_name, int tex_id)
{
    Image *image1;
    //allocate space for texture
    image1 = (Image*) malloc(sizeof(Image));
    //Image not loaded
    if(!ImageLoad(file_name,image1))
    {
        exit(1);
    }

    texture[tex_id] = tex_id;

    glBindTexture(GL_TEXTURE_2D,tex_id);

    glTexImage2D(GL_TEXTURE_2D,0,3,image1->sizeX,image1->sizeY,0,GL_RGB,GL_UNSIGNED_BYTE,image1->data);

    //scale linearly when image is bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //scale linearly when image is smaller than texture

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);

}


void mouse(int b,int s,int mx,int my)
{
   // cout<<"\n frx1="<<fr_x1<<"x="<<x<<"mx"<<mx<<endl;
    double mx1=mx - (800/2);
    double my1=(600-my) - (600/2);

    mx1 = (mx1 / 400) * 5;
    my1 = (my1 / 300) * 5;

   // cout << "mouse : " << mx1 << "," << my1 << endl;
   // cout << "box : " << x << "," << y << endl;
    for (int j = 0; j < num_boxes; j++)
    {


    if(mx1 >= object_x[j]-0.5 && mx1 <= object_x[j]+0.5)
    {
        if (my1 >= object_y[j]-0.5 && my1 <= object_y[j]+0.5)
        {

        //cout<<"\n frx1="<<fr_x1<<"x="<<x<<"mx1"<<mx1<<endl;
        //cout<<"\n frx2="<<fr_x2<<"x="<<x<<"mx1"<<mx1<<endl;
        //cout<<"\n fry1="<<fr_y1<<"y="<<y<<"my1"<<my1<<endl;
        //cout<<"\n fry2="<<fr_y2<<"y="<<y<<"my1"<<my1<<endl;


        mouse_click=1;
        press++;
        miss_object--;


                    object_x[j] = -5.5;
                    object_y[j] = starting_y[j];
                    speed[j] = (float)((rand()%5)+3)/1000.0;



        }
    }

    }
}
static void display(void){
    srand ( time(NULL) );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setOrthographicProjection();

    if(temp==0){
        glColor3d(1.0, 0.0, 1.0);
    glPushMatrix();
    renderBitmapString(300,200,(void *)font," 1 : Start Game !");
    renderBitmapString(300,240,(void *)font,"2: Quit");
    glPopMatrix();

    }

    else if(temp==1)
    {
      glColor3f(100.0/256.0, 0.0, 0.0);

      glColor3f(0.5,0.8, 0.0);
      glRectf(0,0,1280,1024);
      glColor3f(0.8,0.0,0.0);


          if(mouse_click==1)
      {
          mouse_click=0;
      }

        for (int j = 0; j < num_boxes; j++)
        {

                if (object_x[j] > 5.5)
                {
                    object_x[j] = -5.5;
                    object_y[j] = starting_y[j];
                    speed[j] = (float)((rand()%5)+3)/1000.0;
                    miss_object++;
                }

        }



         if(miss_object>20)
          {
           glColor3d(0.0, 0.0, 1.0);

           glPushMatrix();

           renderBitmapString(300,200,(void *)font,"GAME OVER!");
           //score=(char)press;
           IntToChar(press);
           //renderBitmapString(300,240,(void *)font,score);
           glPopMatrix();

           mouse_click=0;


          }

          else
          {
              for (int j = 0; j < num_boxes; j++)
              {
               glMatrixMode(GL_PROJECTION);
               glLoadIdentity();
               gluOrtho2D(-5,5,-5,5);
               glMatrixMode(GL_MODELVIEW);

               glPushMatrix();
                glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[3]);

               glTranslatef(object_x[j],object_y[j],0.0);
               glScalef(1,1,1);
               glRotatef(9.0,9.0,3.0,0.0);
              // glColor3f( 1.0, 0.0, 1.0 );
               //Cube();
               draw_cube(1);

               glPopMatrix();
               glDisable(GL_TEXTURE_2D);



              }

            }



   }


    glutSwapBuffers();
}

void keyboard(unsigned char key,int mx,int my)
{
if(key=='1')
temp=1;
else if(key=='2')
exit(1);

glutPostRedisplay();
}


void animate()
{

           if(temp==1){
             if(miss_object<=20){
              for (int j = 0; j < num_boxes; j++)
              {

                    object_y[j]=object_y[j] + speed[j];
                    object_x[j]=object_x[j] + speed[j];

              }
          }
           }
    glutPostRedisplay();


}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0.0,0.0);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Catch it !");

    glutDisplayFunc(display);
    glutIdleFunc(animate);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);



  loadTexture("E:\\4-2\\4-2\\CSE 4208\\game\\t.bmp", 0);
     loadTexture("E:\\4-2\\4-2\\CSE 4208\\game\\c.bmp", 1);
     loadTexture("E:\\4-2\\4-2\\CSE 4208\\game\\te.bmp", 2);
     loadTexture("E:\\4-2\\4-2\\CSE 4208\\game\\j.bmp", 3);


    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
