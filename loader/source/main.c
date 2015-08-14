/*

Nintendont (Loader) - Playing Gamecubes in Wii mode on a Wii U

Copyright (C) 2013  crediar

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation version 2.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/
#include <gccore.h>
#include <ogc/lwp_watchdog.h>
#include <ogc/lwp_threads.h>
#include <ogc/lwp.h>
#include <wiiuse/wpad.h>
#include <wupc/wupc.h>
#include <di/di.h>
#include <fat.h>
#include <asndlib.h>
#include <mp3player.h>
#include <unistd.h>
#include <sys/dir.h>

#include "exi.h"
#include "dip.h"
#include "global.h"
#include "font.h"
#include "Config.h"
#include "FPad.h"
#include "menu.h"
#include "MemCard.h"
#include "Patches.h"
#include "kernel_bin.h"
#include "multidol_ldr_bin.h"
#include "stub_bin.h"
#include "titles.h"
#include "ipl.h"
#include "HID.h"

#include "bootanim_audio_mp3.h"
#include "gc0_png.h"
#include "gc1_png.h"
#include "gc2_png.h"
#include "gc3_png.h"
#include "gc4_png.h"
#include "gc5_png.h"
#include "gc6_png.h"
#include "gc7_png.h"
#include "gc8_png.h"
#include "gc9_png.h"
#include "gc10_png.h"
#include "gc11_png.h"
#include "gc12_png.h"
#include "gc13_png.h"
#include "gc14_png.h"
#include "gc15_png.h"
#include "gc16_png.h"
#include "gc17_png.h"
#include "gc18_png.h"
#include "gc19_png.h"
#include "gc20_png.h"
#include "gc21_png.h"
#include "gc22_png.h"
#include "gc23_png.h"
#include "gc24_png.h"
#include "gc25_png.h"
#include "gc26_png.h"
#include "gc27_png.h"
#include "gc28_png.h"
#include "gc29_png.h"
#include "gc30_png.h"
#include "gc31_png.h"
#include "gc32_png.h"
#include "gc33_png.h"
#include "gc34_png.h"
#include "gc35_png.h"
#include "gc36_png.h"
#include "gc37_png.h"
#include "gc38_png.h"
#include "gc39_png.h"
#include "gc40_png.h"
#include "gc41_png.h"
#include "gc42_png.h"
#include "gc43_png.h"
#include "gc44_png.h"
#include "gc45_png.h"
#include "gc46_png.h"
#include "gc47_png.h"
#include "gc48_png.h"
#include "gc49_png.h"
#include "gc50_png.h"
#include "gc51_png.h"
#include "gc52_png.h"
#include "gc53_png.h"
#include "gc54_png.h"
#include "gc55_png.h"
#include "gc56_png.h"
#include "gc57_png.h"
#include "gc58_png.h"
#include "gc59_png.h"
#include "gc60_png.h"
#include "gc61_png.h"
#include "gc62_png.h"
#include "gc63_png.h"
#include "gc64_png.h"
#include "gc65_png.h"
#include "gc66_png.h"
#include "gc67_png.h"
#include "gc68_png.h"
#include "gc69_png.h"
#include "gc70_png.h"
#include "gc71_png.h"
#include "gc72_png.h"
#include "gc73_png.h"
#include "gc74_png.h"
#include "gc75_png.h"
#include "gc76_png.h"
#include "gc77_png.h"
#include "gc78_png.h"
#include "gc79_png.h"
#include "gc80_png.h"
#include "gc81_png.h"
#include "gc82_png.h"
#include "gc83_png.h"
#include "gc84_png.h"
#include "gc85_png.h"
#include "gc86_png.h"
#include "gc87_png.h"
#include "gc88_png.h"
#include "gc89_png.h"
#include "gc90_png.h"
#include "gc91_png.h"
#include "gc92_png.h"
#include "gc93_png.h"
#include "gc94_png.h"
#include "gc95_png.h"
#include "gc96_png.h"
#include "gc97_png.h"
#include "gc98_png.h"
#include "gc99_png.h"
#include "gc100_png.h"
#include "gc101_png.h"
#include "gc102_png.h"
#include "gc103_png.h"
#include "gc104_png.h"
#include "gc105_png.h"
#include "gc106_png.h"
#include "gc107_png.h"
#include "gc108_png.h"
#include "gc109_png.h"
#include "gc110_png.h"
#include "gc111_png.h"
#include "gc112_png.h"
#include "gc113_png.h"
#include "gc114_png.h"
#include "gc115_png.h"
#include "gc116_png.h"
#include "gc117_png.h"
#include "gc118_png.h"
#include "gc119_png.h"
#include "gc120_png.h"
#include "gc121_png.h"
#include "gc122_png.h"
#include "gc123_png.h"
#include "gc124_png.h"
#include "gc125_png.h"
#include "gc126_png.h"
#include "gc127_png.h"
#include "gc128_png.h"
#include "gc129_png.h"
#include "gc130_png.h"
#include "gc131_png.h"
#include "gc132_png.h"
#include "gc133_png.h"
#include "gc134_png.h"
#include "gc135_png.h"
#include "gc136_png.h"
#include "gc137_png.h"
#include "gc138_png.h"
#include "gc139_png.h"
#include "gc140_png.h"
#include "gc141_png.h"
#include "gc142_png.h"
#include "gc143_png.h"
#include "gc144_png.h"
#include "gc145_png.h"
#include "gc146_png.h"
#include "gc147_png.h"
#include "gc148_png.h"
#include "gc149_png.h"
#include "gc150_png.h"
#include "gc151_png.h"
#include "gc152_png.h"

extern void __exception_setreload(int t);
extern void __SYS_ReadROM(void *buf,u32 len,u32 offset);
extern u32 __SYS_GetRTC(u32 *gctime);

#define STATUS			((void*)0x90004100)
#define STATUS_LOADING	(*(vu32*)(0x90004100))
#define STATUS_SECTOR	(*(vu32*)(0x90004100 + 8))
#define STATUS_DRIVE	(*(float*)(0x9000410C))
#define STATUS_GB_MB	(*(vu32*)(0x90004100 + 16))
#define STATUS_ERROR	(*(vu32*)(0x90004100 + 20))

#define HW_DIFLAGS		0xD800180
#define MEM_PROT		0xD8B420A

#define IOCTL_ExecSuspendScheduler	1

static GXRModeObj *vmode = NULL;

#define SCREEN_HEIGHT	rmode->efbHeight
#define SCREEN_WIDTH	rmode->fbWidth

static const unsigned char Boot2Patch[] =
{
    0x48, 0x03, 0x49, 0x04, 0x47, 0x78, 0x46, 0xC0, 0xE6, 0x00, 0x08, 0x70, 0xE1, 0x2F, 0xFF, 0x1E, 
    0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x25,
};
static const unsigned char AHBAccessPattern[] =
{
	0x68, 0x5B, 0x22, 0xEC, 0x00, 0x52, 0x18, 0x9B, 0x68, 0x1B, 0x46, 0x98, 0x07, 0xDB,
};
static const unsigned char AHBAccessPatch[] =
{
	0x68, 0x5B, 0x22, 0xEC, 0x00, 0x52, 0x18, 0x9B, 0x23, 0x01, 0x46, 0x98, 0x07, 0xDB,
};
static const unsigned char FSAccessPattern[] =
{
    0x9B, 0x05, 0x40, 0x03, 0x99, 0x05, 0x42, 0x8B, 
};
static const unsigned char FSAccessPatch[] =
{
    0x9B, 0x05, 0x40, 0x03, 0x1C, 0x0B, 0x42, 0x8B, 
};

// Forbid the use of MEM2 through malloc
u32 MALLOC_MEM2 = 0;

s32 __IOS_LoadStartupIOS(void)
{
	int res;

	res = __ES_Init();
	if(res < 0)
		return res;

	return 0;
}

extern DISC_INTERFACE __io_custom_usbstorage;
extern vu32 FoundVersion;
vu32 KernelLoaded = 0;
u32 entrypoint = 0;
char launch_dir[MAXPATHLEN] = {0};
extern void __exception_closeall();
static u8 loader_stub[0x1800]; //save internally to prevent overwriting
static ioctlv IOCTL_Buf ALIGNED(32);
static const char ARGSBOOT_STR[9] ALIGNED(0x10) = {'a','r','g','s','b','o','o','t','\0'}; //makes it easier to go through the file
static const char NIN_BUILD_STRING[] ALIGNED(32) = NIN_VERSION_STRING; // Version detection string used by nintendont launchers "$$Version:x.xxx"

lwp_t init_async_tp;
bool usb_isinit=false;

void *init_async(void *xx) {
	// Run this async too for slow HDDs.
	time_t timeout = time(NULL);
	while(time(NULL) - timeout < 10)
	{
		if (usb_isinit) return NULL; // Init was canceled.
		if(__io_custom_usbstorage.startup() && __io_custom_usbstorage.isInserted())
			break;
		usleep(50000);
	}//*/
	usb_isinit=true;
	return NULL;
}//*/

GRRLIB_texImg *nextbootframe;

void doSaveSettings() {
	FILE *cfg;
	char ConfigPath[20];
	// Todo: detects the boot device to prevent writing twice on the same one
	sprintf(ConfigPath, "/nincfg.bin"); // writes config to boot device, loaded on next launch
	if (doautoboot) remove(ConfigPath); else {
		cfg = fopen(ConfigPath, "wb");
		if( cfg != NULL )
		{
			fwrite( ncfg, sizeof(NIN_CFG), 1, cfg );
			fclose( cfg );
		}
	}
	sprintf(ConfigPath, "%s:/nincfg.bin", GetRootDevice()); // writes config to game device, used by kernel
	if (doautoboot) remove(ConfigPath); else {
		cfg = fopen(ConfigPath, "wb");
		if( cfg != NULL )
		{
			fwrite( ncfg, sizeof(NIN_CFG), 1, cfg );
			fclose( cfg );
		}
	}
}

int main(int argc, char **argv)
{
	doautoboot = false;
	// Exit after 10 seconds if there is an error
	__exception_setreload(10);
//	u64 timeout = 0;
	CheckForGecko();
	DCInvalidateRange(loader_stub, 0x1800);
	memcpy(loader_stub, (void*)0x80001800, 0x1800);

	RAMInit();

	//Meh, doesnt do anything anymore anyways
	//STM_RegisterEventHandler(HandleSTMEvent);

	Initialize();

	u32 u;
	//Disables MEMPROT for patches
	write16(MEM_PROT, 0);
	//Patches FS access
	for( u = 0x93A00000; u < 0x94000000; u+=2 )
	{
		if( memcmp( (void*)(u), FSAccessPattern, sizeof(FSAccessPattern) ) == 0 )
		{
		//	gprintf("FSAccessPatch:%08X\r\n", u );
			memcpy( (void*)u, FSAccessPatch, sizeof(FSAccessPatch) );
			DCFlushRange((void*)u, sizeof(FSAccessPatch));
			break;
		}
	}

	//for BT.c
	CONF_GetPadDevices((conf_pads*)0x932C0000);
	DCFlushRange((void*)0x932C0000, sizeof(conf_pads));
	*(vu32*)0x932C0490 = CONF_GetIRSensitivity();
	*(vu32*)0x932C0494 = CONF_GetSensorBarPosition();
	DCFlushRange((void*)0x932C0490, 8);

	if(LoadKernel() < 0)
	{
		ClearScreen();
		gprintf("Failed to load kernel from NAND!\r\n");
		PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, 232, "Failed to load kernel from NAND!" );
		ExitToLoader(1);
	}
	InsertModule((char*)kernel_bin, kernel_bin_size);

	memset( (void*)0x92f00000, 0, 0x100000 );
	DCFlushRange( (void*)0x92f00000, 0x100000 );

	DCInvalidateRange( (void*)0x939F02F0, 0x20 );

	memcpy( (void*)0x939F02F0, Boot2Patch, sizeof(Boot2Patch) );

	DCFlushRange( (void*)0x939F02F0, 0x20 );

	//libogc still has that, lets close it
	__ES_Close();
	s32 fd = IOS_Open( "/dev/es", 0 );

	memset( STATUS, 0xFFFFFFFF, 0x20  );
	DCFlushRange( STATUS, 0x20 );

	memset( (void*)0x91000000, 0xFFFFFFFF, 0x20  );
	DCFlushRange( (void*)0x91000000, 0x20 );

	*(vu32*)0xD3003420 = 0; //make sure kernel doesnt reload

	raw_irq_handler_t irq_handler = BeforeIOSReload();
	IOS_IoctlvAsync( fd, 0x1F, 0, 0, &IOCTL_Buf, NULL, NULL );
	AfterIOSReload( irq_handler, FoundVersion );

	while(1)
	{
		DCInvalidateRange( STATUS, 0x20 );
		if((STATUS_LOADING > 0 || abs(STATUS_LOADING) > 1) && STATUS_LOADING < 20)
		{
			gprintf("Kernel sent signal\n");
			break;
		}
	}

	LWP_CreateThread(&init_async_tp, init_async, NULL, NULL, 0, 2);

	FILE *meta = fopen("meta.xml", "w");
	if(meta != NULL)
	{
		fprintf(meta, "%s\r\n<app version=\"1\">\r\n\t<name>%s</name>\r\n", META_XML, META_NAME);
		fprintf(meta, "\t<coder>%s</coder>\r\n\t<version>%d.%d</version>\r\n", META_AUTHOR, NIN_VERSION>>16, NIN_VERSION&0xFFFF);
		fprintf(meta, "\t<release_date>20140430000000</release_date>\r\n");
		fprintf(meta, "\t<short_description>%s</short_description>\r\n", META_SHORT);
		fprintf(meta, "\t<long_description>%s\r\n\r\n%s</long_description>\r\n", META_LONG1, META_LONG2);
		fprintf(meta, "\t<ahb_access/>\r\n</app>");
		fclose(meta);
	}
	
	fatInitDefault();

	gprintf("Nintendont at your service!\r\n%s\r\n", NIN_BUILD_STRING);
	KernelLoaded = 1;

	char* first_slash = strrchr(argv[0], '/');
	if (first_slash != NULL) strncpy(launch_dir, argv[0], first_slash-argv[0]+1);
	gprintf("launch_dir = %s\r\n", launch_dir);

	FPAD_Init();
	FPAD_Update();

	/*PrintInfo();
	PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + + 430, MENU_POS_Y + 20*1, "Home: Exit");
	PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + + 430, MENU_POS_Y + 20*2, "A   : Select");
	GRRLIB_Render();
	ClearScreen();//*/

	/* Read IPL Font before doing any patches */
	void *fontbuffer = memalign(32, 0x50000);
	__SYS_ReadROM((void*)fontbuffer,0x50000,0x1AFF00);
	memcpy((void*)0xD3100000, fontbuffer, 0x50000);
	DCInvalidateRange( (void*)0x93100000, 0x50000 );
	free(fontbuffer);
	//gprintf("Font: 0x1AFF00 starts with %.4s, 0x1FCF00 with %.4s\n", (char*)0x93100000, (char*)0x93100000 + 0x4D000);

	// Simple code to autoupdate the meta.xml in Nintendont's folder
	LoadTitles();

	memset((void*)ncfg, 0, sizeof(NIN_CFG));

	bool argsboot = false;
	if(argc > 1) //every 0x00 gets counted as one arg so just make sure its more than the path and copy
	{
		memcpy(ncfg, argv[1], sizeof(NIN_CFG));
		if (ncfg->Version == 2)	//need to upgrade config from ver 2 to ver 3
		{
			ncfg->MemCardBlocks = 0x2;//251 blocks
			ncfg->Version = 3;
		}
		if(ncfg->Magicbytes == 0x01070CF6 && ncfg->Version == NIN_CFG_VERSION && ncfg->MaxPads <= NIN_CFG_MAXPAD)
		{
			if(ncfg->Config & NIN_CFG_AUTO_BOOT)
			{	//do NOT remove, this can be used to see if nintendont knows args
				gprintf(ARGSBOOT_STR);
				argsboot = true;
			}
		}
	}
	if(!argsboot)
	{
		if (!LoadNinCFG())
		{
			memset(ncfg, 0, sizeof(NIN_CFG));

			ncfg->Magicbytes = 0x01070CF6;
			ncfg->Version = NIN_CFG_VERSION;
			ncfg->Language = NIN_LAN_AUTO;
			ncfg->MaxPads = NIN_CFG_MAXPAD;
			ncfg->MemCardBlocks = 0x2;//251 blocks
		}

		// Prevent autobooting if B is pressed
		/*int i = 0;
		while((ncfg->Config & NIN_CFG_AUTO_BOOT) && i < 1000000) // wait for wiimote re-synch
		{
			if (i == 0) {
				PrintInfo();
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, 320 - 90, MENU_POS_Y + 20*10, "B: Cancel Autoboot");
				GRRLIB_Render();
				ClearScreen();
			}
			
			FPAD_Update();

			if (FPAD_Cancel(0)) {
				ncfg->Config &= ~NIN_CFG_AUTO_BOOT;
				break;
			}

			i++;
		}//*/
	}
	
	doautoboot = (ncfg->Config & NIN_CFG_AUTO_BOOT);
	if (doautoboot) doSaveSettings();
	
	UseSD = (ncfg->Config & NIN_CFG_USB) == 0;

	bool progressive = (CONF_GetProgressiveScan() > 0) && VIDEO_HaveComponentCable();
	if(progressive) //important to prevent blackscreens
		ncfg->VideoMode |= NIN_VID_PROG;
	else
		ncfg->VideoMode &= ~NIN_VID_PROG;

	if(!doautoboot)
	{
		int i;
		for (i=0; i<255; i +=15) // Fade background image in from black screen
		{
			GRRLIB_DrawImg(0, 0, background, 0, 1, 1, RGBA(255, 255, 255, i)); // Opacity increases as i does
			GRRLIB_Render();
		}
			GRRLIB_DrawImg(0, 0, background, 0, 1, 1, RGBA(255, 255, 255, 255)); // Opacity increases as i does
		while (1)
		{
			VIDEO_WaitVSync();
			FPAD_Update();

			UseSD = (ncfg->Config & NIN_CFG_USB) == 0;
			PrintInfo();
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + 430, MENU_POS_Y + 20*1, "Home: Exit");
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + 430, MENU_POS_Y + 20*2, "A   : Select");
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + 53 * 6 - 8, MENU_POS_Y + 20 * 6, UseSD ? ARROW_LEFT : "");
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + 53 * 6 - 8, MENU_POS_Y + 20 * 7, UseSD ? "" : ARROW_LEFT);
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + 47 * 6 - 8, MENU_POS_Y + 20 * 6, " SD  ");
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + 47 * 6 - 8, MENU_POS_Y + 20 * 7, "USB  ");

			if (FPAD_OK(0))
				break;

			if (FPAD_Start(1))
			{
				ClearScreen();
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, 212, 232, "Returning to loader...");
				ExitToLoader(0);
			}
			if (FPAD_Down(0))
				ncfg->Config = ncfg->Config | NIN_CFG_USB;

			if (FPAD_Up(0))
				ncfg->Config = ncfg->Config & ~NIN_CFG_USB;

			GRRLIB_Render();
			ClearScreen();
		}
		ClearScreen();
		PrintFormat(DEFAULT_SIZE, TEXTCOLOR, 212, 232, "Loading, please wait...");
		GRRLIB_Render();
		ClearScreen();
	}

	/*FILE *out = fopen("/kernel.bin", "wb");
	fwrite( (char*)0x90100000, 1, NKernelSize, out );
	fclose(out);*/

//Load config

//Reset drive

	bool SaveSettings = false;
	if( doautoboot ) {
		gprintf("Autobooting:\"%s\"\r\n", ncfg->GamePath );
		
			// Boot animation here:
			
			GRRLIB_Render();
			
			
			const u8 *gcbootanim[] = {gc0_png
				, gc1_png
				, gc2_png
				, gc3_png
				, gc4_png
				, gc5_png
				, gc6_png
				, gc7_png
				, gc8_png
				, gc9_png
				, gc10_png
				, gc11_png
				, gc12_png
				, gc13_png
				, gc14_png
				, gc15_png
				, gc16_png
				, gc17_png
				, gc18_png
				, gc19_png
				, gc20_png
				, gc21_png
				, gc22_png
				, gc23_png
				, gc24_png
				, gc25_png
				, gc26_png
				, gc27_png
				, gc28_png
				, gc29_png
				, gc30_png
				, gc31_png
				, gc32_png
				, gc33_png
				, gc34_png
				, gc35_png
				, gc36_png
				, gc37_png
				, gc38_png
				, gc39_png
				, gc40_png
				, gc41_png
				, gc42_png
				, gc43_png
				, gc44_png
				, gc45_png
				, gc46_png
				, gc47_png
				, gc48_png
				, gc49_png
				, gc50_png
				, gc51_png
				, gc52_png
				, gc53_png
				, gc54_png
				, gc55_png
				, gc56_png
				, gc57_png
				, gc58_png
				, gc59_png
				, gc60_png
				, gc61_png
				, gc62_png
				, gc63_png
				, gc64_png
				, gc65_png
				, gc66_png
				, gc67_png
				, gc68_png
				, gc69_png
				, gc70_png
				, gc71_png
				, gc72_png
				, gc73_png
				, gc74_png
				, gc75_png
				, gc76_png
				, gc77_png
				, gc78_png
				, gc79_png
				, gc80_png
				, gc81_png
				, gc82_png
				, gc83_png
				, gc84_png
				, gc85_png
				, gc86_png
				, gc87_png
				, gc88_png
				, gc89_png
				, gc90_png
				, gc91_png
				, gc92_png
				, gc93_png
				, gc94_png
				, gc95_png
				, gc96_png
				, gc97_png
				, gc98_png
				, gc99_png
				, gc100_png
				, gc101_png
				, gc102_png
				, gc103_png
				, gc104_png
				, gc105_png
				, gc106_png
				, gc107_png
				, gc108_png
				, gc109_png
				, gc110_png
				, gc111_png
				, gc112_png
				, gc113_png
				, gc114_png
				, gc115_png
				, gc116_png
				, gc117_png
				, gc118_png
				, gc119_png
				, gc120_png
				, gc121_png
				, gc122_png
				, gc123_png
				, gc124_png
				, gc125_png
				, gc126_png
				, gc127_png
				, gc128_png
				, gc129_png
				, gc130_png
				, gc131_png
				, gc132_png
				, gc133_png
				, gc134_png
				, gc135_png
				, gc136_png
				, gc137_png
				, gc138_png
				, gc139_png
				, gc140_png
				, gc141_png
				, gc142_png
				, gc143_png
				, gc144_png
				, gc145_png
				, gc146_png
				, gc147_png
				, gc148_png
				, gc149_png
				, gc150_png
				, gc151_png
				, gc152_png
			};

			ASND_Init(NULL);
			MP3Player_Init();
			
			MP3Player_PlayBuffer(bootanim_audio_mp3, bootanim_audio_mp3_size, NULL);
			
			int c;
			GRRLIB_texImg *p1;
			nextbootframe = NULL;
			p1 = GRRLIB_LoadTexture(gcbootanim[0]);
			for (c = 0; c < 153; c++) {
				if (nextbootframe != NULL) GRRLIB_FreeTexture(nextbootframe);
				GRRLIB_FillScreen(0x000000FF);
				GRRLIB_DrawImg((SCREEN_WIDTH-p1->w)/2, (SCREEN_HEIGHT-p1->h)/2+20, p1, 0, 1, 1, RGBA(255, 255, 255, 255));
				nextbootframe = p1;
				if (c != 152) {
					p1 = GRRLIB_LoadTexture(gcbootanim[c+1]);
					//nextbootframepath = gcbootanim[c+1];
					//nextbootframeloaded = false;
					//LWP_CreateThread(&loadnextbootframe_tp, loadnextbootframe, NULL, NULL, 0, 2);
				}
				GRRLIB_Render();
				//while (!nextbootframeloaded){}
			}
			//GRRLIB_FreeTexture(nextbootframe);
			
	} else
		SaveSettings = SelectGame();

	u32 CurDICMD = 0;
	//Init DI and set correct ID if needed
	if( memcmp(ncfg->GamePath, "di", 3) == 0 )
	{
		if (!doautoboot) {
			ClearScreen();
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, 212, 232, "Loading, please wait...");
			GRRLIB_Render();
			ClearScreen();
		}

		DI_UseCache(false);
		DI_Init();
		DI_Mount();
		while (DI_GetStatus() & DVD_INIT)
			usleep(20000);
		if(!(DI_GetStatus() & DVD_READY))
		{
			ClearScreen();
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, 232, "The Disc Drive could not be initialized!" );
			ExitToLoader(1);
		}
		DI_Close();

		u8 *DIBuf = memalign(32,0x800);
		memset(DIBuf, 0, 0x20);
		DCFlushRange(DIBuf, 0x20);
		CurDICMD = DIP_CMD_NORMAL;
		ReadRealDisc(DIBuf, 0, 0x20, CurDICMD);
		if( IsGCGame(DIBuf) == false )
		{
			memset(DIBuf, 0, 0x800);
			DCFlushRange(DIBuf, 0x800);
			CurDICMD = DIP_CMD_DVDR;
			ReadRealDisc(DIBuf, 0, 0x800, CurDICMD);
			if( IsGCGame(DIBuf) == false )
			{
				free(DIBuf);
				ClearScreen();
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, 232, "The Disc in the Drive is not a GC Disc!" );
				ExitToLoader(1);
			}
		}
		memcpy(&(ncfg->GameID), DIBuf, 4);
		free(DIBuf);
	}

	if(SaveSettings) doSaveSettings();
	u32 ISOShift = 0;
	if(memcmp(&(ncfg->GameID), "COBR", 4) == 0 || memcmp(&(ncfg->GameID), "GGCO", 4) == 0
		|| memcmp(&(ncfg->GameID), "GCOP", 4) == 0 || memcmp(&(ncfg->GameID), "RGCO", 4) == 0)
	{
		u32 i, j = 0;
		u32 Offsets[15];
		gameinfo gi[15];
		FILE *f = NULL;
		u8 *MultiHdr = memalign(32, 0x800);
		u8 *GameHdr = memalign(32, 0x800);
		if(CurDICMD)
		{
			ReadRealDisc(MultiHdr, 0, 0x800, CurDICMD);
		}
		else if(strstr(ncfg->GamePath, ".iso") != NULL)
		{
			char GamePath[255];
			sprintf( GamePath, "%s:%s", GetRootDevice(), ncfg->GamePath );
			f = fopen(GamePath, "rb");
			fread(MultiHdr,1,0x800,f);
		}
		u32 NeedShift = (*(vu32*)(MultiHdr+4) == 0x44564439);
		for(i = 0x40; i < 0x100; i += 4)
		{
			u32 TmpOffset = *(vu32*)(MultiHdr+i);
			if(TmpOffset > 0)
			{
				Offsets[j] = NeedShift ? TmpOffset << 2 : TmpOffset;
				if(CurDICMD)
				{
					ReadRealDisc(GameHdr, Offsets[j], 0x800, CurDICMD);
				}
				else
				{
					fseek(f, Offsets[j], SEEK_SET);
					fread(GameHdr, 1, 0x800, f);
				}
				memcpy(gi[j].ID, GameHdr, 6);
				gi[j].Name = strdup((char*)GameHdr+0x20);
				j++;
				if(j == 15) break;
			}
		}
		free(GameHdr);
		free(MultiHdr);
		if(f) fclose(f);
		bool redraw = 1;
		ClearScreen();
		u32 PosX = 0;
		u32 UpHeld = 0, DownHeld = 0;
		while(1)
		{
			VIDEO_WaitVSync();
			FPAD_Update();
			if( FPAD_OK(0) )
				break;
			else if( FPAD_Down(1) )
			{
				if(DownHeld == 0 || DownHeld > 10)
				{
					PosX++;
					if(PosX == j) PosX = 0;
					redraw = true;
				}
				DownHeld++;
			}
			else
				DownHeld = 0;
			if( FPAD_Up(1) )
			{
				if(UpHeld == 0 || UpHeld > 10)
				{
					if(PosX == 0) PosX = j;
					PosX--;
					redraw = true;
				}
				UpHeld++;
			}
			else
				UpHeld = 0;
			if( redraw )
			{
				PrintInfo();
				for( i=0; i < j; ++i )
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*5 + i * 20, "%50.50s [%.6s]%s", gi[i].Name, gi[i].ID, i == PosX ? ARROW_LEFT : " " );
				GRRLIB_Render();
				Screenshot();
				ClearScreen();
				redraw = false;
			}
		}
		ISOShift = Offsets[PosX];
		memcpy(&(ncfg->GameID), gi[PosX].ID, 4);
	}
	*(vu32*)0xD300300C = ISOShift; //multi-iso games

	//Set Language
	if(ncfg->Language == NIN_LAN_AUTO)
	{
		switch (CONF_GetLanguage())
		{
			case CONF_LANG_GERMAN:
				ncfg->Language = NIN_LAN_GERMAN;
				break;
			case CONF_LANG_FRENCH:
				ncfg->Language = NIN_LAN_FRENCH;
				break;
			case CONF_LANG_SPANISH:
				ncfg->Language = NIN_LAN_SPANISH;
				break;
			case CONF_LANG_ITALIAN:
				ncfg->Language = NIN_LAN_ITALIAN;
				break;
			case CONF_LANG_DUTCH:
				ncfg->Language = NIN_LAN_DUTCH;
				break;
			default:
				ncfg->Language = NIN_LAN_ENGLISH;
				break;
		}
	}

//setup memory card
	if(ncfg->Config & NIN_CFG_MEMCARDEMU)
	{
		char BasePath[20];
		sprintf(BasePath, "%s:/saves", GetRootDevice());
		mkdir(BasePath, S_IREAD | S_IWRITE);
		char MemCardName[8];
		memset(MemCardName, 0, 8);
		if ( ncfg->Config & NIN_CFG_MC_MULTI )
		{
			if ((ncfg->GameID & 0xFF) == 'J')  // JPN games
				memcpy(MemCardName, "ninmemj", 7);
			else
				memcpy(MemCardName, "ninmem", 6);
		}
		else
			memcpy(MemCardName, &(ncfg->GameID), 4);
		char MemCard[30];
		sprintf(MemCard, "%s/%s.raw", BasePath, MemCardName);
		gprintf("Using %s as Memory Card.\r\n", MemCard);
		FILE *f = fopen(MemCard, "rb");
		if(f == NULL)
		{
			if(!GenerateMemCard(MemCard))
			{
				ClearScreen();
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, 232, "Failed to create Memory Card File!" );
				ExitToLoader(1);
			}
		}
		else
			fclose(f);
	}
	void *iplbuf = NULL;
	bool useipl = false;
	bool useipltri = false;
	if(IsTRIGame(ncfg->GamePath) == false && (ncfg->Config & NIN_CFG_MEMCARDEMU))
	{
		char iplchar[32];
		if((ncfg->GameID & 0xFF) == 'E')
			sprintf(iplchar, "%s:/iplusa.bin", GetRootDevice());
		else if((ncfg->GameID & 0xFF) == 'J')
			sprintf(iplchar, "%s:/ipljap.bin", GetRootDevice());
		else
			sprintf(iplchar, "%s:/iplpal.bin", GetRootDevice());
		FILE *f = fopen(iplchar, "rb");
		if(f != NULL)
		{
			fseek(f, 0, SEEK_END);
			size_t fsize = ftell(f);
			if(fsize == 2097152)
			{
				fseek(f, 0, SEEK_SET);
				iplbuf = malloc(2097152);
				fread(iplbuf, 1, 2097152, f);
				useipl = true;
			}
			fclose(f);
		}
	}
	else if(IsTRIGame(ncfg->GamePath) == true)
	{
		char iplchar[32];
		sprintf(iplchar, "%s:/segaboot.bin", GetRootDevice());
		FILE *f = fopen(iplchar, "rb");
		if(f != NULL)
		{
			fseek(f, 0, SEEK_END);
			size_t fsize = ftell(f);
			if(fsize == 1048576)
			{
				fseek(f, 0x20, SEEK_SET);
				void *iplbuf = (void*)0x92A80000;
				fread(iplbuf, 1, 1048576 - 0x20, f);
				DCFlushRange(iplbuf, 1048576);
				useipltri = true;
			}
			fclose(f);
		}
	}
//sync changes
	CloseDevices();

	WPAD_Disconnect(0);
	WPAD_Disconnect(1);
	WPAD_Disconnect(2);
	WPAD_Disconnect(3);

	WUPC_Shutdown();
	WPAD_Shutdown();

//make sure the cfg gets to the kernel
	DCStoreRange((void*)ncfg, sizeof(NIN_CFG));

	*(vu32*)0xD3003420 = 0x0DEA;
	int sf = 250;
	while(1)
	{
		DCInvalidateRange( STATUS, 0x20 );
		if( STATUS_LOADING == 0xdeadbeef )
			break;

		//PrintInfo();

		if (!doautoboot) {
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*6, "Loading patched kernel... %d", STATUS_LOADING);
			if(STATUS_LOADING == 0)
			{
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*7, "ES_Init...");
				// Cleans the -1 when it's past it to avoid confusion if another error happens. e.g. before it showed "81" instead of "8" if the controller was unplugged.
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X + 163, MENU_POS_Y + 20*6, " ");
			}
			if((STATUS_LOADING > 0 || abs(STATUS_LOADING) > 1) && STATUS_LOADING < 20)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*7, "ES_Init... Done!");
			if(STATUS_LOADING == 2)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*8, "Initing storage devices...");
			if(abs(STATUS_LOADING) > 2 && abs(STATUS_LOADING) < 20)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*8, "Initing storage devices... Done!");
		}
		if(STATUS_LOADING == -2)
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*8, "Initing storage devices... Error! %d  Shutting down", STATUS_ERROR);
		if (!doautoboot) {
			if(STATUS_LOADING == 3)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*9, "Mounting USB/SD device...");
			if(abs(STATUS_LOADING) > 3 && abs(STATUS_LOADING) < 20)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*9, "Mounting USB/SD device... Done!");
		}
		if(STATUS_LOADING == -3)
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*9, "Mounting USB/SD device... Error! %d  Shutting down", STATUS_ERROR);
		if(STATUS_LOADING == 5) {
/* 			if (timeout == 0)
				timeout = ticks_to_secs(gettime()) + 20; // Set timer for 20 seconds
			else if (timeout <= ticks_to_secs(gettime())) {
				STATUS_ERROR = -7;
				DCFlushRange(STATUS, 0x20);
				usleep(100);
				//memset( (void*)0x92f00000, 0, 0x100000 );
				//DCFlushRange( (void*)0x92f00000, 0x100000 );
				//ExitToLoader(1);
			}*/
			if (!doautoboot || (STATUS_ERROR == -7)) PrintFormat(DEFAULT_SIZE, (STATUS_ERROR == -7) ? TEXTCOLOR_ERROR:TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*10, (STATUS_ERROR == -7) ? "Checking FS... Timeout!" : "Checking FS...");
		}
		if (!doautoboot) {
			if(abs(STATUS_LOADING) > 5 && abs(STATUS_LOADING) < 20)
			{
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*10, "Checking FS... Done!");
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*11, "Drive size: %.02f%s Sector size: %d", STATUS_DRIVE, STATUS_GB_MB ? "GB" : "MB", STATUS_SECTOR);
			}
		}
		if(STATUS_LOADING == -5)
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*10, "Checking FS... Error! %d Shutting down", STATUS_ERROR);
		if (!doautoboot) {
			if(STATUS_LOADING == 6)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*12, "ES_LoadModules...");
			if(abs(STATUS_LOADING) > 6 && abs(STATUS_LOADING) < 20)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*12, "ES_LoadModules... Done!");
		}
		if(STATUS_LOADING == -6)
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*12, "ES_LoadModules... Error! %d Shutting down", STATUS_ERROR);
		if (!doautoboot) {
			if(STATUS_LOADING == 7)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*13, "Loading config...");
			if(abs(STATUS_LOADING) > 7 && abs(STATUS_LOADING) < 20)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*13, "Loading config... Done!");
		}
		/*if(STATUS_LOADING == 8)
		{
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init HID devices... ");
			if ( STATUS_ERROR == 1)
			{
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*15, "          Make sure the Controller is plugged in");
			}
			else
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*15, "%50s", " ");
		}
		if(abs(STATUS_LOADING) > 8 && abs(STATUS_LOADING) < 20)
		{
			if (ncfg->Config & NIN_CFG_NATIVE_SI)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init HID devices... Using ONLY NATIVE Gamecube Ports");
			else if ((ncfg->MaxPads == 1) && (ncfg->Config & NIN_CFG_HID))
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init HID devices... Using Gamecube and HID Ports");
			else if ((ncfg->MaxPads > 0) && (ncfg->Config & NIN_CFG_HID))
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init HID devices... Using Gamecube, HID, and BT Ports");
			else if (ncfg->MaxPads > 0)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init HID devices... Using Gamecube and BT Ports");
			else if (ncfg->Config & NIN_CFG_HID)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init HID devices... Using HID and Bluetooth Ports");
			else
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init HID devices... Using Bluetooth Ports... Done!");
		}
		if(STATUS_LOADING == -8)
		{
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*14, "Init HID devices... Failed! Shutting down");
			switch (STATUS_ERROR)
			{
				case -1:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "No Controller plugged in! %25s", " ");
					break;
				case -2:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "Missing %s:/controller.ini %20s", GetRootDevice(), " ");
					break;
				case -3:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "Controller does not match %s:/controller.ini %6s", GetRootDevice(), " ");
					break;
				case -4:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "Invalid Polltype in %s:/controller.ini %12s", GetRootDevice(), " ");
					break;
				case -5:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "Invalid DPAD value in %s:/controller.ini %9s", GetRootDevice(), " ");
					break;
				case -6:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "PS3 controller init error %25s", " ");
					break;
				case -7:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "Gamecube adapter for Wii u init error %13s", " ");
					break;
				default:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "Unknown error %d %35s", STATUS_ERROR, " ");
					break;
			}
		}*/
		if (!doautoboot) {
			if(STATUS_LOADING == 9)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init DI... %40s", " ");
			if(abs(STATUS_LOADING) > 9 && abs(STATUS_LOADING) < 20)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*14, "Init DI... Done! %35s", " ");
			if(STATUS_LOADING == 10)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*15, "Init CARD...");
			if(abs(STATUS_LOADING) > 10 && abs(STATUS_LOADING) < 20)
				PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*15, "Init CARD... Done!");
		}
		if(STATUS_LOADING == -10)
		{
			PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*15, "Init CARD... Failed! Shutting down");
			switch (STATUS_ERROR)
			{
				case -1:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*16, "Missing %s:/sneek/kenobiwii.bin", GetRootDevice());
					break;
				case -2:
					if (ncfg->Config & NIN_CFG_CHEAT_PATH)
						PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*16, "Missing %s:/%s", GetRootDevice(), ncfg->CheatPath);
					else
						PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*16, "Missing %s:/games/GAMEID/GAMEID.gct", GetRootDevice());
					break;
				case -3:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*16, "Cheat file to large", GetRootDevice());
					break;
				case -4:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*16, "Cheat path is empty", GetRootDevice());
					break;
				default:
					PrintFormat(DEFAULT_SIZE, TEXTCOLOR_ERROR, MENU_POS_X, MENU_POS_Y + 20*16, "Unknown error %d %35s", STATUS_ERROR, " ");
					break;
			}
		}
		if (!doautoboot || ((STATUS_LOADING < -1) && (STATUS_LOADING > -20))) {
			GRRLIB_Screen2Texture(0, 0, screen_buffer, GX_FALSE); // Copy all status messages
			GRRLIB_Render();
			ClearScreen();
		}
		while((STATUS_LOADING < -1) && (STATUS_LOADING > -20)) //displaying a fatal error
				; //do nothing wait for shutdown
	}
	DrawBuffer(); // Draw all status messages
	if (doautoboot) {
		while (sf > 0) {
			GRRLIB_FillScreen(0x000000FF);
			GRRLIB_DrawImg((SCREEN_WIDTH-nextbootframe->w)/2, (SCREEN_HEIGHT-nextbootframe->h)/2+20, nextbootframe, 0, 1, 1, RGBA(255, 255, 255, sf));
			GRRLIB_Render();
			sf -= 10;
		}
		GRRLIB_Render();
		GRRLIB_Render();
		GRRLIB_FreeTexture(nextbootframe);
	} else {
		PrintFormat(DEFAULT_SIZE, TEXTCOLOR, MENU_POS_X, MENU_POS_Y + 20*17, "Nintendont kernel looping.");
		PrintFormat(DEFAULT_SIZE, TEXTCOLOR_SUCCESS, MENU_POS_X, MENU_POS_Y + 20*18, "Loading game...");
		GRRLIB_Render();
		DrawBuffer(); // Draw all status messages
	}
//	memcpy( (void*)0x80000000, (void*)0x90140000, 0x1200000 );
	GRRLIB_FreeTexture(background);
	GRRLIB_FreeTexture(screen_buffer);
	GRRLIB_FreeTTF(myFont);
	GRRLIB_Exit();

	gprintf("GameRegion:");

	if( ncfg->VideoMode & NIN_VID_FORCE )
	{
		gprintf("Force:%02X\r\n", ncfg->VideoMode & NIN_VID_FORCE_MASK );

		switch( ncfg->VideoMode & NIN_VID_FORCE_MASK )
		{
			case NIN_VID_FORCE_NTSC:
			{
				*(vu32*)0x800000CC = 0;
				Region = 0;
			} break;
			case NIN_VID_FORCE_MPAL:
			{
				*(vu32*)0x800000CC = 3;
				Region = 2;
			} break;
			case NIN_VID_FORCE_PAL50:
			{
				*(vu32*)0x800000CC = 1;
				Region = 2;
			} break;
			case NIN_VID_FORCE_PAL60:
			{
				*(vu32*)0x800000CC = 5;
				Region = 2;
			} break;
		}
	}
	else
	{
		switch (ncfg->GameID & 0x000000FF)
		{
			// EUR
			case 'D':
			case 'F':
			case 'H':
			case 'I':
			case 'M':
			case 'P':
			case 'S':
			case 'U':
			case 'X':
			case 'Y':
			case 'Z':
				Region = 2;
				break;
			// JP and US
			case 'J':
			case 'E':
			default:
				Region = 0;
				break;
		}
	}
	
	gprintf("Region:%u\r\n", Region );
	progressive = ncfg->Config & NIN_CFG_FORCE_PROG;
	switch(Region)
	{
		default:
		case 0:
		case 1:
		{
			gprintf("NTSC\r\n");

			*(vu32*)0x800000CC = 0;

			if(progressive)
				vmode = &TVNtsc480Prog;
			else
				vmode = &TVNtsc480IntDf;
			
		} break;
		case 2:
		{
			if( *(vu32*)0x800000CC == 5 )
			{
				gprintf("PAL60\r\n");

				if(progressive)
					vmode = &TVNtsc480Prog;
				else
					vmode = &TVEurgb60Hz480IntDf;

			} else if( *(vu32*)0x800000CC == 3 ) {
				gprintf("MPAL\r\n");

				if(progressive)
					vmode = &TVNtsc480Prog;
				else
					vmode = &TVMpal480IntDf;
			} else {
				
				gprintf("PAL50\r\n");

				if(progressive)
					vmode = &TVEurgb60Hz480Prog;
				else
					vmode = &TVPal528IntDf;
			}

			*(vu32*)0x800000CC = 1;

		} break;
	}
	VIDEO_Configure( vmode );
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(vmode->viTVMode & VI_NON_INTERLACE)
		VIDEO_WaitVSync();
	else while(VIDEO_GetNextField())
		VIDEO_WaitVSync();

	*(u16*)(0xCC00501A) = 156;	// DSP refresh rate
	/* from libogc, get all gc pads to work */
	u32 buf[2];
	u32 bits = 0;
	u8 chan;
	for(chan = 0; chan < 4; ++chan)
	{
		bits |= (0x80000000>>chan);
		SI_GetResponse(chan,(void*)buf);
		SI_SetCommand(chan,(0x00000300|0x00400000));
		SI_EnablePolling(bits);
	}
	*(vu32*)0xD3003004 = 1; //ready up HID Thread

	VIDEO_SetBlack(TRUE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(vmode->viTVMode & VI_NON_INTERLACE)
		VIDEO_WaitVSync();
	else while(VIDEO_GetNextField())
		VIDEO_WaitVSync();
	GX_AbortFrame();

	// set current time
	u32 bias = 0, cur_time = 0;
	__SYS_GetRTC(&cur_time);
	if(CONF_GetCounterBias(&bias) >= 0)
		cur_time += bias;
	settime(secs_to_ticks(cur_time));

	DCInvalidateRange((void*)0x93000000, 0x3000);
	memset((void*)0x93002700, 0, 0x200); //clears alot of pad stuff
	memset((void*)0x93002C00, 0, 0x400); //clears alot of multidol stuff
	strcpy((char*)0x930028A0, "ARStartDMA: %08x %08x %08x\n"); //ARStartDMA Debug
	DCFlushRange((void*)0x93000000, 0x3000);

	DCInvalidateRange((void*)0x93010010, 0x10000);
	memcpy((void*)0x93010010, loader_stub, 0x1800);
	memcpy((void*)0x93011810, stub_bin, stub_bin_size);
	DCFlushRange((void*)0x93010010, 0x10000);

	DCInvalidateRange((void*)0x93020000, 0x10000);
	memset((void*)0x93020000, 0, 0x10000);
	DCFlushRange((void*)0x93020000, 0x10000);

	DCInvalidateRange((void*)0x93003000, 0x20);
	//*(vu32*)0x93003000 = currev; //set kernel rev (now in LoadKernel)
	*(vu32*)0x93003008 = 0x80000004; //just some address for SIGetType
	//0x9300300C is already used for multi-iso
	memset((void*)0x93003010, 0, 0x10); //disable rumble on bootup
	DCFlushRange((void*)0x93003000, 0x20);

	//lets prevent weird events
	__STM_Close();

	//THIS thing right here, it interrupts some games and breaks them
	//To fix that, call ExecSuspendScheduler so WC24 just sleeps
	u32 out = 0;
	fd = IOS_Open("/dev/net/kd/request", 0);
	IOS_Ioctl(fd, IOCTL_ExecSuspendScheduler, NULL, 0, &out, 4);
	IOS_Close(fd);

	write16(0xD8B420A, 0); //disable MEMPROT again after reload
	//u32 level = IRQ_Disable();
	__exception_closeall();
	__lwp_thread_closeall();

	DVDStartCache(); //waits for kernel start
	gprintf("Game Start\n");

	if(useipl)
	{
		load_ipl(iplbuf);
		*(vu32*)0xD3003420 = 0x5DEA;
		while(*(vu32*)0xD3003420 == 0x5DEA) ;
		/* Patches */
		DCInvalidateRange((void*)0x80001800, 0x1800);
		ICInvalidateRange((void*)0x80001800, 0x1800);
		/* IPL */
		DCInvalidateRange((void*)0x81300000, 0x300000);
		ICInvalidateRange((void*)0x81300000, 0x300000);
		/* Seems to boot more stable this way */
		//gprintf("Using 32kHz DSP (No Resample)\n");
		write32(0xCD806C00, 0x68);
		free(iplbuf);
	}
	else //use our own loader
	{
		if(useipltri)
		{
			*(vu32*)0xD3003420 = 0x6DEA;
			while(*(vu32*)0xD3003420 == 0x6DEA) ;
		}
		memcpy((void*)0x81300000, multidol_ldr_bin, multidol_ldr_bin_size);
		DCFlushRange((void*)0x81300000, multidol_ldr_bin_size);
		ICInvalidateRange((void*)0x81300000, multidol_ldr_bin_size);
	}
	asm volatile (
		"lis %r3, 0x8130\n"
		"mtlr %r3\n"
		"blr\n"
	);
	//IRQ_Restore(level);

	return 0;
}

