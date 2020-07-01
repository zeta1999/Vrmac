﻿// g++ printEnums.cpp -o printEnums
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/videodev2.h>
#include <stdint.h>

void fileEnums()
{
	struct sValue { int number; const char* text; };
	std::vector<sValue> vec;
#define A( V ) vec.push_back( sValue{ V, #V } )
	A( O_APPEND );
	A( O_ASYNC );
	A( O_CLOEXEC );
	A( O_CREAT );
	A( O_DIRECT );
	A( O_DIRECTORY );
	A( O_EXCL );
	A( O_LARGEFILE );
	A( O_NOATIME );
	A( O_NOCTTY );
	A( O_NOFOLLOW );
	A( O_NONBLOCK );
	A( O_SYNC );
	A( O_TRUNC );

	std::sort( vec.begin(), vec.end(), []( const sValue& a, const sValue& b ) { return a.number < b.number; } );
	for( auto& i : vec )
		printf( "%s = 0x%x,\n", i.text, i.number );
}

void videoIoctlEnums()
{
	struct sValue { uint32_t number; const char* text; };
	std::vector<sValue> vec;

	// Regex re = new Regex( @"^\s*#\s*define\s+(VIDIOC_[\S]+)\s" );
	A( VIDIOC_QUERYCAP );
	A( VIDIOC_RESERVED );
	A( VIDIOC_ENUM_FMT );
	A( VIDIOC_G_FMT );
	A( VIDIOC_S_FMT );
	A( VIDIOC_REQBUFS );
	A( VIDIOC_QUERYBUF );
	A( VIDIOC_G_FBUF );
	A( VIDIOC_S_FBUF );
	A( VIDIOC_OVERLAY );
	A( VIDIOC_QBUF );
	A( VIDIOC_EXPBUF );
	A( VIDIOC_DQBUF );
	A( VIDIOC_STREAMON );
	A( VIDIOC_STREAMOFF );
	A( VIDIOC_G_PARM );
	A( VIDIOC_S_PARM );
	A( VIDIOC_G_STD );
	A( VIDIOC_S_STD );
	A( VIDIOC_ENUMSTD );
	A( VIDIOC_ENUMINPUT );
	A( VIDIOC_G_CTRL );
	A( VIDIOC_S_CTRL );
	A( VIDIOC_G_TUNER );
	A( VIDIOC_S_TUNER );
	A( VIDIOC_G_AUDIO );
	A( VIDIOC_S_AUDIO );
	A( VIDIOC_QUERYCTRL );
	A( VIDIOC_QUERYMENU );
	A( VIDIOC_G_INPUT );
	A( VIDIOC_S_INPUT );
	A( VIDIOC_G_EDID );
	A( VIDIOC_S_EDID );
	A( VIDIOC_G_OUTPUT );
	A( VIDIOC_S_OUTPUT );
	A( VIDIOC_ENUMOUTPUT );
	A( VIDIOC_G_AUDOUT );
	A( VIDIOC_S_AUDOUT );
	A( VIDIOC_G_MODULATOR );
	A( VIDIOC_S_MODULATOR );
	A( VIDIOC_G_FREQUENCY );
	A( VIDIOC_S_FREQUENCY );
	A( VIDIOC_CROPCAP );
	A( VIDIOC_G_CROP );
	A( VIDIOC_S_CROP );
	A( VIDIOC_G_JPEGCOMP );
	A( VIDIOC_S_JPEGCOMP );
	A( VIDIOC_QUERYSTD );
	A( VIDIOC_TRY_FMT );
	A( VIDIOC_ENUMAUDIO );
	A( VIDIOC_ENUMAUDOUT );
	A( VIDIOC_G_PRIORITY );
	A( VIDIOC_S_PRIORITY );
	A( VIDIOC_G_SLICED_VBI_CAP );
	A( VIDIOC_LOG_STATUS );
	A( VIDIOC_G_EXT_CTRLS );
	A( VIDIOC_S_EXT_CTRLS );
	A( VIDIOC_TRY_EXT_CTRLS );
	A( VIDIOC_ENUM_FRAMESIZES );
	A( VIDIOC_ENUM_FRAMEINTERVALS );
	A( VIDIOC_G_ENC_INDEX );
	A( VIDIOC_ENCODER_CMD );
	A( VIDIOC_TRY_ENCODER_CMD );
	A( VIDIOC_DBG_S_REGISTER );
	A( VIDIOC_DBG_G_REGISTER );
	A( VIDIOC_S_HW_FREQ_SEEK );
	A( VIDIOC_S_DV_TIMINGS );
	A( VIDIOC_G_DV_TIMINGS );
	A( VIDIOC_DQEVENT );
	A( VIDIOC_SUBSCRIBE_EVENT );
	A( VIDIOC_UNSUBSCRIBE_EVENT );
	A( VIDIOC_CREATE_BUFS );
	A( VIDIOC_PREPARE_BUF );
	A( VIDIOC_G_SELECTION );
	A( VIDIOC_S_SELECTION );
	A( VIDIOC_DECODER_CMD );
	A( VIDIOC_TRY_DECODER_CMD );
	A( VIDIOC_ENUM_DV_TIMINGS );
	A( VIDIOC_QUERY_DV_TIMINGS );
	A( VIDIOC_DV_TIMINGS_CAP );
	A( VIDIOC_ENUM_FREQ_BANDS );
	A( VIDIOC_DBG_G_CHIP_INFO );
	A( VIDIOC_QUERY_EXT_CTRL );

	for( auto& i : vec )
		printf( "%s = 0x%x,\n", i.text + 7, i.number );
}

void videoPixelFormats()
{
	struct sValue { uint32_t number; const char* text; };
	std::vector<sValue> vec;

	// Regex re = new Regex( @"^\s*#\s*define\s+(V4L2_PIX_FMT_[\S]+)\s" );
	A( V4L2_PIX_FMT_RGB332 );
	A( V4L2_PIX_FMT_RGB444 );
	A( V4L2_PIX_FMT_ARGB444 );
	A( V4L2_PIX_FMT_XRGB444 );
	A( V4L2_PIX_FMT_RGB555 );
	A( V4L2_PIX_FMT_ARGB555 );
	A( V4L2_PIX_FMT_XRGB555 );
	A( V4L2_PIX_FMT_RGB565 );
	A( V4L2_PIX_FMT_RGB555X );
	A( V4L2_PIX_FMT_ARGB555X );
	A( V4L2_PIX_FMT_XRGB555X );
	A( V4L2_PIX_FMT_RGB565X );
	A( V4L2_PIX_FMT_BGR666 );
	A( V4L2_PIX_FMT_BGR24 );
	A( V4L2_PIX_FMT_RGB24 );
	A( V4L2_PIX_FMT_BGR32 );
	A( V4L2_PIX_FMT_ABGR32 );
	A( V4L2_PIX_FMT_XBGR32 );
	A( V4L2_PIX_FMT_RGB32 );
	A( V4L2_PIX_FMT_ARGB32 );
	A( V4L2_PIX_FMT_XRGB32 );
	A( V4L2_PIX_FMT_GREY );
	A( V4L2_PIX_FMT_Y4 );
	A( V4L2_PIX_FMT_Y6 );
	A( V4L2_PIX_FMT_Y10 );
	A( V4L2_PIX_FMT_Y12 );
	A( V4L2_PIX_FMT_Y16 );
	A( V4L2_PIX_FMT_Y16_BE );
	A( V4L2_PIX_FMT_Y10BPACK );
	A( V4L2_PIX_FMT_PAL8 );
	A( V4L2_PIX_FMT_UV8 );
	A( V4L2_PIX_FMT_YUYV );
	A( V4L2_PIX_FMT_YYUV );
	A( V4L2_PIX_FMT_YVYU );
	A( V4L2_PIX_FMT_UYVY );
	A( V4L2_PIX_FMT_VYUY );
	A( V4L2_PIX_FMT_Y41P );
	A( V4L2_PIX_FMT_YUV444 );
	A( V4L2_PIX_FMT_YUV555 );
	A( V4L2_PIX_FMT_YUV565 );
	A( V4L2_PIX_FMT_YUV32 );
	A( V4L2_PIX_FMT_HI240 );
	A( V4L2_PIX_FMT_HM12 );
	A( V4L2_PIX_FMT_M420 );
	A( V4L2_PIX_FMT_NV12 );
	A( V4L2_PIX_FMT_NV21 );
	A( V4L2_PIX_FMT_NV16 );
	A( V4L2_PIX_FMT_NV61 );
	A( V4L2_PIX_FMT_NV24 );
	A( V4L2_PIX_FMT_NV42 );
	A( V4L2_PIX_FMT_NV12M );
	A( V4L2_PIX_FMT_NV21M );
	A( V4L2_PIX_FMT_NV16M );
	A( V4L2_PIX_FMT_NV61M );
	A( V4L2_PIX_FMT_NV12MT );
	A( V4L2_PIX_FMT_NV12MT_16X16 );
	A( V4L2_PIX_FMT_YUV410 );
	A( V4L2_PIX_FMT_YVU410 );
	A( V4L2_PIX_FMT_YUV411P );
	A( V4L2_PIX_FMT_YUV420 );
	A( V4L2_PIX_FMT_YVU420 );
	A( V4L2_PIX_FMT_YUV422P );
	A( V4L2_PIX_FMT_YUV420M );
	A( V4L2_PIX_FMT_YVU420M );
	A( V4L2_PIX_FMT_YUV422M );
	A( V4L2_PIX_FMT_YVU422M );
	A( V4L2_PIX_FMT_YUV444M );
	A( V4L2_PIX_FMT_YVU444M );
	A( V4L2_PIX_FMT_SBGGR8 );
	A( V4L2_PIX_FMT_SGBRG8 );
	A( V4L2_PIX_FMT_SGRBG8 );
	A( V4L2_PIX_FMT_SRGGB8 );
	A( V4L2_PIX_FMT_SBGGR10 );
	A( V4L2_PIX_FMT_SGBRG10 );
	A( V4L2_PIX_FMT_SGRBG10 );
	A( V4L2_PIX_FMT_SRGGB10 );
	A( V4L2_PIX_FMT_SBGGR10P );
	A( V4L2_PIX_FMT_SGBRG10P );
	A( V4L2_PIX_FMT_SGRBG10P );
	A( V4L2_PIX_FMT_SRGGB10P );
	A( V4L2_PIX_FMT_SBGGR10ALAW8 );
	A( V4L2_PIX_FMT_SGBRG10ALAW8 );
	A( V4L2_PIX_FMT_SGRBG10ALAW8 );
	A( V4L2_PIX_FMT_SRGGB10ALAW8 );
	A( V4L2_PIX_FMT_SBGGR10DPCM8 );
	A( V4L2_PIX_FMT_SGBRG10DPCM8 );
	A( V4L2_PIX_FMT_SGRBG10DPCM8 );
	A( V4L2_PIX_FMT_SRGGB10DPCM8 );
	A( V4L2_PIX_FMT_SBGGR12 );
	A( V4L2_PIX_FMT_SGBRG12 );
	A( V4L2_PIX_FMT_SGRBG12 );
	A( V4L2_PIX_FMT_SRGGB12 );
	A( V4L2_PIX_FMT_SBGGR12P );
	A( V4L2_PIX_FMT_SGBRG12P );
	A( V4L2_PIX_FMT_SGRBG12P );
	A( V4L2_PIX_FMT_SRGGB12P );
	A( V4L2_PIX_FMT_SBGGR16 );
	A( V4L2_PIX_FMT_SGBRG16 );
	A( V4L2_PIX_FMT_SGRBG16 );
	A( V4L2_PIX_FMT_SRGGB16 );
	A( V4L2_PIX_FMT_HSV24 );
	A( V4L2_PIX_FMT_HSV32 );
	A( V4L2_PIX_FMT_MJPEG );
	A( V4L2_PIX_FMT_JPEG );
	A( V4L2_PIX_FMT_DV );
	A( V4L2_PIX_FMT_MPEG );
	A( V4L2_PIX_FMT_H264 );
	A( V4L2_PIX_FMT_H264_NO_SC );
	A( V4L2_PIX_FMT_H264_MVC );
	A( V4L2_PIX_FMT_H263 );
	A( V4L2_PIX_FMT_MPEG1 );
	A( V4L2_PIX_FMT_MPEG2 );
	A( V4L2_PIX_FMT_MPEG4 );
	A( V4L2_PIX_FMT_XVID );
	A( V4L2_PIX_FMT_VC1_ANNEX_G );
	A( V4L2_PIX_FMT_VC1_ANNEX_L );
	A( V4L2_PIX_FMT_VP8 );
	A( V4L2_PIX_FMT_VP9 );
	A( V4L2_PIX_FMT_HEVC );
	A( V4L2_PIX_FMT_CPIA1 );
	A( V4L2_PIX_FMT_WNVA );
	A( V4L2_PIX_FMT_SN9C10X );
	A( V4L2_PIX_FMT_SN9C20X_I420 );
	A( V4L2_PIX_FMT_PWC1 );
	A( V4L2_PIX_FMT_PWC2 );
	A( V4L2_PIX_FMT_ET61X251 );
	A( V4L2_PIX_FMT_SPCA501 );
	A( V4L2_PIX_FMT_SPCA505 );
	A( V4L2_PIX_FMT_SPCA508 );
	A( V4L2_PIX_FMT_SPCA561 );
	A( V4L2_PIX_FMT_PAC207 );
	A( V4L2_PIX_FMT_MR97310A );
	A( V4L2_PIX_FMT_JL2005BCD );
	A( V4L2_PIX_FMT_SN9C2028 );
	A( V4L2_PIX_FMT_SQ905C );
	A( V4L2_PIX_FMT_PJPG );
	A( V4L2_PIX_FMT_OV511 );
	A( V4L2_PIX_FMT_OV518 );
	A( V4L2_PIX_FMT_STV0680 );
	A( V4L2_PIX_FMT_TM6000 );
	A( V4L2_PIX_FMT_CIT_YYVYUY );
	A( V4L2_PIX_FMT_KONICA420 );
	A( V4L2_PIX_FMT_JPGL );
	A( V4L2_PIX_FMT_SE401 );
	A( V4L2_PIX_FMT_S5C_UYVY_JPG );
	A( V4L2_PIX_FMT_Y8I );
	A( V4L2_PIX_FMT_Y12I );
	A( V4L2_PIX_FMT_Z16 );
	A( V4L2_PIX_FMT_MT21C );
	A( V4L2_PIX_FMT_INZI );
	A( V4L2_PIX_FMT_IPU3_SBGGR10 );
	A( V4L2_PIX_FMT_IPU3_SGBRG10 );
	A( V4L2_PIX_FMT_IPU3_SGRBG10 );
	A( V4L2_PIX_FMT_IPU3_SRGGB10 );
	A( V4L2_PIX_FMT_PRIV_MAGIC );
	A( V4L2_PIX_FMT_FLAG_PREMUL_ALPHA );

	for( auto& i : vec )
		printf( "%s = 0x%x,\n", i.text + 13, i.number );
}

int main()
{
	// fileEnums();
	// videoIoctlEnums();
	videoPixelFormats();
	return 0;
}