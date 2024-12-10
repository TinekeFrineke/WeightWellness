//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <memory>
#include <vector>

#include "XmlClass.h"

namespace ww2024
{

// Forward declarations
class XmlDag;


class XmlWeek : public XmlClass
{
public:
    enum class strategie
    {
        KCal,
        Koolhydraten
    };

    XmlWeek();
    ~XmlWeek() override;

    const std::vector<std::unique_ptr<XmlDag>> & GetDagList() const;
    void Add(std::unique_ptr<XmlDag> aDag);
    std::wstring Getbegindatum() const;
    std::wstring Geteinddatum() const;
    double Getpunten() const;
    double Getweekpunten() const;
    double Getstartweight() const;
    strategie Getstrategie() const;
    void Setbegindatum(const std::wstring & abegindatum);
    void Seteinddatum(const std::wstring & aeinddatum);
    void Setpunten(double apunten);
    void Setweekpunten(double aweekpunten);
    void Setstartweight(double astartweight);
    void Setstrategie(strategie astrategie);

private:
    XmlWeek(const XmlWeek& anOriginal) = delete;
    XmlWeek& operator=(const XmlWeek& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlDag>> mDagList;
    std::wstring mbegindatum;
    std::wstring meinddatum;
    double mpunten;
    double mweekpunten;
    double mstartweight;
    strategie mstrategie;
};


}
