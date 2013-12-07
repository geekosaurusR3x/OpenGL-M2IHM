#include "fonctions.h"

using namespace std;

/* Fonction de chargement d'une image jpeg*/
unsigned char * loadJpegImage(std::string fichie,jpeg_decompress_struct *cinfo)
{
  
	unsigned char *image;
	const char *fichier = fichie.c_str();
     struct jpeg_error_mgr jerr;
     FILE *file;
     unsigned char *ligne;
 
     cinfo->err = jpeg_std_error(&jerr);
     jpeg_create_decompress(cinfo);
	 file=fopen(fichier,"rb" );
     if (file==NULL)
      {
		  throw jpeg_load_exception(fichier,"No sutch file or directory");
       }
     jpeg_stdio_src(cinfo, file);
     jpeg_read_header(cinfo, TRUE);
     image= new unsigned char [cinfo->image_width*cinfo->image_height*3];
     if (cinfo->jpeg_color_space==JCS_GRAYSCALE)
	{
       throw jpeg_load_exception(fichier,"File is not in RGBA mode");
     }
  
     jpeg_start_decompress(cinfo);
     ligne=image;
     while (cinfo->output_scanline<cinfo->output_height)
      {
         ligne=image+3*cinfo->image_height*cinfo->output_scanline;
         jpeg_read_scanlines(cinfo,&ligne,1);
       }
     jpeg_finish_decompress(cinfo);
     jpeg_destroy_decompress(cinfo);
     return image;
   
  }
  
  void loadJpegTexture(std::string fichie, int numtext)
  {
	  struct jpeg_decompress_struct cinfo;
	  unsigned char *image = loadJpegImage(fichie,&cinfo);
	  setTexture(image,cinfo.image_width,cinfo.image_height,numtext);
	  free(image);
  
  }
  
  void setTexture(unsigned char *image,int width,int height,int numtext)
  {
	  /* Paramétrage de la texture */
     glBindTexture(GL_TEXTURE_2D,numtext);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	 glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
	  
  }
float RandFloat(float start, float end) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = end - start;
    float result = random * diff;
    return start + result;
}
