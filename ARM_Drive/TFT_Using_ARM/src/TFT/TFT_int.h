/*
 * TFT_int.h
 *
 *  Created on: Jan 31, 2024
 *      Author: userH
 */

#ifndef TFT_TFT_INT_H_
#define TFT_TFT_INT_H_


void HTFT_vInit(void);

void HTFT_vShowImage(u16 A_puImg[],u32 A_u32ImgSize );

void HTFT_vSetXpos(u16 A_u16Xstart,u16 A_u16Xend);

void HTFT_vSetYpos(u16 A_u16Ystart,u16 A_u16Yend);
void HTFT_vFillRectangle(u8 x1,u8 x2 ,u8 y1,u8 y2 ,u16 A_u16Color);
void HTFT_vFillBackGround(u16 A_u16Color);


#endif /* TFT_TFT_INT_H_ */
