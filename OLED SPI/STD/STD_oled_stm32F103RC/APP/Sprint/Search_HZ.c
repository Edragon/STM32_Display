
/*****************************************************************************************************


     �����ֿ��ѯ�ַ��Ĵ�����ʽ



*****************************************************************************************************/

#include "Search_HZ.H"

//extern unsigned char DF_buffer[528];

unsigned char SP_DATA[72];//ȡһ���ַ��Ļ�����

/*************������λ���ѯ��ʽ����ѯ�ַ����ڻ�������ָ���ַ *************************************/

/*************************************************************************************************
 ��������Char_Addr
 ���������
           unsigned char qh,             �ַ���λ��ƫ�Ƶ���
           unsigned char wh,             �ַ���λ��ƫ�Ƶ�λ
           unsigned char *Data_char      �����ַ��ķ��ػ�����ָ��

		   // ADDRESS=((qh-0xa1-0x0f)*94+(wh-0xa1))*72;  //24�����������еĵ�ַ

***************************************************************************************************/ 


 
void Char_Addr(unsigned char qh,unsigned char wh)//�������Ϊ���ֵ���λ����
 {
   
   unsigned int ADDRESS;
   unsigned int ADDRESS1;
   unsigned int ADDRESS2;
   unsigned char ADDRESS3;
   unsigned char ADDRESS4;
  
   ADDRESS3=qh-0xa1; //-0x0f��ʹ��DOS�ֿ��ʱ����Ҫ��ȥ0xf;//һ�������ǽ���������ֽ���㣬��ֹ����������
   
   ADDRESS4=wh-0xa1;
   
   ADDRESS2=(unsigned int)ADDRESS3*94;
   
   ADDRESS1=ADDRESS2+(unsigned int)ADDRESS4;
   
   ADDRESS=(ADDRESS1*72)+0x3000;//0x3000֮ǰ�ĵ�ַ��ŵ�ΪASC��λ��

   SPI_Flash_Read(SP_DATA,ADDRESS,72);//��ȡSPI FLASH ��ָ����ַ��ʼ��ȡָ�����ȵ�����   

 }
 
 
 
 
 
 
 
 
 
 
/*************************************ASC˳����ҵ����ַ�*************************************************/

/*********************************************************************************************************
 ��������ASC_Addr
 �������ܣ���ȡASC������ַ�
 
 ���������
           unsigned char qh,             �ַ���λ��ƫ�Ƶ���
           unsigned char wh,             �ַ���λ��ƫ�Ƶ�λ
           unsigned char *Data_char      �����ַ��ķ��ػ�����ָ��
***************************************************************************************************/ 


 
void ASC_Addr(unsigned char QW)
 {
   
   unsigned int ADDRESS;
    
   ADDRESS=(unsigned int)QW*48;  //16*24����ASCII�������еĵ�ַ
    
   SPI_Flash_Read(SP_DATA,ADDRESS,48);//��ȡSPI FLASH ��ָ����ַ��ʼ��ȡָ�����ȵ�����   
  
 
 } 
