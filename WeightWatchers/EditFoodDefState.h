//#ifndef WW_WEIGHTWATCHERS_EDITFOODDEFSTATE_H__
//#define WW_WEIGHTWATCHERS_EDITFOODDEFSTATE_H__
//
//
////#include "WW/WWModel/VoedingsmiddelDefinitie.h"
//
//namespace WW
//{
//class CalculatedVMDef;
//class FixedVMDef;
//}
//
//
//class CEditFoodDefState
//{
//public:
//  virtual void                Accept() = 0;
//  virtual void                RollBack() = 0;
//};
//
//
//class CEditCalculatedFoodDefState : public CEditFoodDefState
//{
//public:
//                              CEditCalculatedFoodDefState(WW::CalculatedVMDef & aDefinitie);
//
//  virtual void                Accept();
//  virtual void                RollBack();
//
//private:
//  WW::FoodParameters          mOriginalParameters;
//  WW::CalculatedVMDef &       mDefinitie;
//};
//
//
//class CEditFixedFoodDefState : public CEditFoodDefState
//{
//public:
//                              CEditFixedFoodDefState(WW::FixedVMDef & aDefinitie);
//
//  virtual void                Accept();
//  virtual void                RollBack();
//
//private:
//  double                      mOldPointsPerPortie;
//  WW::FixedVMDef &            mDefinitie;
//};
//
//
//#endif // WW_WEIGHTWATCHERS_EDITFOODDEFSTATE_H__