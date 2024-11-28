//#ifndef WW_WEIGHTWATCHERS_EDITFOODDEFSTATE_H__
//#define WW_WEIGHTWATCHERS_EDITFOODDEFSTATE_H__
//
//
////#include "weight/WWModel/VoedingsmiddelDefinitie.h"
//
//namespace weight
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
//                              CEditCalculatedFoodDefState(weight::CalculatedVMDef & aDefinitie);
//
//  virtual void                Accept();
//  virtual void                RollBack();
//
//private:
//  weight::FoodParameters          mOriginalParameters;
//  weight::CalculatedVMDef &       mDefinitie;
//};
//
//
//class CEditFixedFoodDefState : public CEditFoodDefState
//{
//public:
//                              CEditFixedFoodDefState(weight::FixedVMDef & aDefinitie);
//
//  virtual void                Accept();
//  virtual void                RollBack();
//
//private:
//  double                      mOldPointsPerPortie;
//  weight::FixedVMDef &            mDefinitie;
//};
//
//
//#endif // WW_WEIGHTWATCHERS_EDITFOODDEFSTATE_H__