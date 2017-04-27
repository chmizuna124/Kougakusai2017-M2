#include "KunokunoMotors.h"

KunokunoMotors* KunokunoMotors::_instance = 0;

KunokunoMotors* KunokunoMotors::getInstance(){
	if(_instance == 0){
		_instance = new KunokunoMotors();
	}
	return _instance;
}

KunokunoMotors::KunokunoMotors()
	:rWheel(PORT_C),
	lWheel(PORT_B),
	pushingArm(PORT_D, MEDIUM_MOTOR),
    backArm(PORT_A, MEDIUM_MOTOR)
	{

    motorReset();

	preFMoterCount = 0;
	preLMoterCount = 0;
	preRMoterCount = 0;
}

void KunokunoMotors::update(){
	preFMoterCount = rWheel.getCount();
	preLMoterCount = lWheel.getCount();
	preRMoterCount = pushingArm.getCount();
}

//リセット////////////////////////////////////////////////////////////////////////////////
void KunokunoMotors::motorReset(){
	rWheel.reset();
	lWheel.reset();
	pushingArm.reset();
    backArm.reset();
}

//エンコーダ値初期化////////////////////////////////////////////////////////////////////////
void KunokunoMotors::initCount(){
	rWheel.setCount(rWheel.getCount());
	lWheel.setCount(lWheel.getCount());
	pushingArm.setCount(pushingArm.getCount());
}

//エンコーダ値取得//////////////////////////////////////////////////////////////////////////
int32_t KunokunoMotors::getPushingArmCount(){
	return pushingArm.getCount();
}
int32_t KunokunoMotors::getBackArmCount(){
	return backArm.getCount();
}
int32_t KunokunoMotors::getWheelCount(){
	return rWheel.getCount();
}

//PWMセット////////////////////////////////////////////////////////////////////////////////
void KunokunoMotors::setPushingArmPWM(int pwm){
	pushingArm.setPWM(pwm);
}
void KunokunoMotors::setBackArmPWM(int pwm){
	backArm.setPWM(pwm);
}
void KunokunoMotors::setWheelPWM(int pwm){
	rWheel.setPWM(pwm);
	lWheel.setPWM(pwm);
}
void KunokunoMotors::setAllPWM(int pushingArm,int backArm,int wheel){
	this->pushingArm.setPWM(pushingArm);
	this->backArm.setPWM(backArm);
	this->rWheel.setPWM(wheel);
	this->lWheel.setPWM(wheel);
}

