#include "Other.h"
Realtek_R_Audio::Realtek_R_Audio() : Audio() {}

std::string Realtek_R_Audio::info() {
    return "Audio: Realtek R audio system";
}
Audio* Realtek_R_Audio::clone()
{
    return new Realtek_R_Audio;
}

HiFiAudioSystem::HiFiAudioSystem() : Audio() {}

std::string HiFiAudioSystem::info() {
    return "Audio: Realtek R audio system";
}
Audio* HiFiAudioSystem::clone() 
{
    return new HiFiAudioSystem;
}

VintageAirConditioner::VintageAirConditioner() : AirConditioner() {}

std::string VintageAirConditioner::info() {
    return "Conditioner: Vintage air conditioner";
}
AirConditioner* VintageAirConditioner::clone() {
    return new VintageAirConditioner;
}

TwoZoneClimateControl::TwoZoneClimateControl() : AirConditioner() {}

std::string TwoZoneClimateControl::info()  {
    return "Conditioner: Two Zone Climate Control and air conditioner";
}
AirConditioner* TwoZoneClimateControl::clone()  {
    return new TwoZoneClimateControl;
}

std::string StandardPropeller::getinfo()
{
    return "Propeller: Standard";
}
double StandardPropeller::getAccelerator()
{
    return 1;
}
Propeller* StandardPropeller::clone()
{
    return new StandardPropeller;
}

std::string CarbonPropeller::getinfo()
{
    return "Propeller: Carbon";
}
double CarbonPropeller::getAccelerator()
{
    return 1.5;
}
Propeller* CarbonPropeller::clone()
{
    return new CarbonPropeller;
}

std::string RTX4090::getinfo()
{
    return "Propeller: Nvidia GeForce RTX 4090";
}
double RTX4090::getAccelerator()
{
    return 999;
}
Propeller* RTX4090::clone()
{
    return new RTX4090;
}
void Weapon::setTarget(float lat, float lng) {
    this->lat = lat;
    this->lng = lng;
}
void  Weapon::loadAmmo() {
    loaded = true;
}
void Minigun::shoot(std::pair<float, float> coords)  {
    loadAmmo();
    setTarget(coords.first, coords.second);
    if (lat == 0 || lng == 0) {
        throw "Invalid target";
    }
    std::cout << "Target destroyed" << std::endl;
    loaded = false;
    lat = 0;
    lng = 0;
}
int Minigun::rechargetime()
{
    return 1000;
}
std::string  Minigun::info() 
{
    return "Weapon: Minigun";
}
Weapon*  Minigun::clone()
{
    return new Minigun;
}
int Artillery::rechargetime()
{
    return 3500;
}
void Artillery::shoot(std::pair<float, float> coords) {
    loadAmmo();
    setTarget(coords.first, coords.second);
    if (lat == 0 || lng == 0) {
        throw "Invalid target";
    }
    std::cout << "Target destroyed" << std::endl;
    loaded = false;
    lat = 0;
    lng = 0;
}
std::string Artillery::info() 
{
    return "Weapon: Artillery";
}
Weapon* Artillery::clone() 
{
    return new Artillery;
}

void Flamethrower::shoot(std::pair<float, float> coords) {
    loadAmmo();
    setTarget(coords.first, coords.second);
    if (lat == 0 || lng == 0) {
        throw "Invalid target";
    }
    std::cout << "Target destroyed" << std::endl;
    loaded = false;
    lat = 0;
    lng = 0;
}
std::string  Flamethrower::info() 
{
    return "Weapon: Flamethrower";
}
Weapon*  Flamethrower::clone() 
{
    return new Flamethrower;
}

int  Flamethrower::rechargetime()
{
    return 800;
}
M777HowitzerWeaponAdapter::M777HowitzerWeaponAdapter() {
    howitzer = new M777Howitzer();
}
void M777HowitzerWeaponAdapter::shoot(std::pair<float, float> coords) {
    howitzer->loadAmmo();
    howitzer->setTarget(coords.first, coords.second);
    howitzer->fire();
}
M777HowitzerWeaponAdapter::~M777HowitzerWeaponAdapter() {
    delete howitzer;
}
std::string M777HowitzerWeaponAdapter::info() {
    return "Weapon: M777Howitzer(adapted)";
}
int M777HowitzerWeaponAdapter::rechargetime()
{
    return 700;
}
M777HowitzerWeaponAdapter* M777HowitzerWeaponAdapter::clone() {
    return new M777HowitzerWeaponAdapter();
}
