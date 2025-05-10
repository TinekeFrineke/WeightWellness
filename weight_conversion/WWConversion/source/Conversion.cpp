// Conversion.cpp : Defines the entry point for the console application.
//

#include "model/ModelFactory.h"
#include "xmlreader/XmlReader.h"
#include "xmlwriter/XmlWriter.h"

#include <xercesc/util/PlatformUtils.hpp>

#include "MessageHandler.h"


int main(int argc, char* argv[])
{
    if (argc < 3)
        return -1;

    std::string logfile = "logfile.txt";
    if (argc == 4)
        logfile = argv[3];

    auto messageHandler(std::make_shared<MessageHandler>());
    weight::ModelFactory factory(messageHandler);
    auto model = factory.CreateModel();

    XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();

    ww_1_2::XmlReader reader(logfile, *model, messageHandler);
    reader.Read(argv[1]);

    ww2024::XmlWriter writer(*model);
    writer.Write(argv[2]);

    XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();

    return 0;
}

