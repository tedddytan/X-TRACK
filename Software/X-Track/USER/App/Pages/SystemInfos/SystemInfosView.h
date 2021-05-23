#ifndef __SYSTEM_INFOS_VIEW_H
#define __SYSTEM_INFOS_VIEW_H

#include "../Page.h"

class SystemInfosView {
public:
    void Create(lv_obj_t* root);
    void Delete();

public:
    typedef struct {
        lv_obj_t* cont;
        lv_obj_t* icon;
        lv_obj_t* labelInfo;
        lv_obj_t* labelData;
    }item_t;

    struct {
        item_t sport;
        item_t gps;
        item_t mag;
        item_t imu;
        item_t rtc;
        item_t battery;
        item_t storage;
        item_t system;
        lv_group_t* group;
    }ui;

public:
    void SetSport(
        float trip, 
        const char* time, 
        float maxSpd
    );
    void SetGPS(
        float lat,
        float lng,
        float alt,
        const char* utc,
        float course,
        float speed
    );
    void SetMAG(
        float dir,
        int x,
        int y,
        int z
    );
    void SetIMU(
        int step,
        const char* info
    );
    void SetRTC(
        const char* dateTime
    );
    void SetBattery(
        int usage,
        float voltage,
        const char* state
    );
    void SetStorage(
        const char* usage,
        const char* version
    );
    void SetSystem(
        const char* sysVer,
        const char* lvglVer,
        const char* compile,
        const char* bootTime
    );

    void SetScrollToY(lv_obj_t* obj, lv_coord_t y, lv_anim_enable_t en);
    static void onFocus(lv_group_t* e);

private:
    struct {
        lv_style_t icon;
        lv_style_t focus;
        lv_style_t info;
        lv_style_t data;
    }style;

private:
    void Group_Init();
    void Style_Init();
    void Style_Reset();
    void Item_Create(
        item_t* item,
        lv_obj_t* par,
        const char* name,
        const char* img_src,
        const char* infos
    );
};

#endif // !__VIEW_H