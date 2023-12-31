#include "player.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("DongCiDaCi");
    QCoreApplication::setApplicationVersion("1.0.0");
    QCoreApplication::setOrganizationName("X");

    QCommandLineParser parser;
    QCommandLineOption customAudioRoleOption("custom-audio-role",
                                             "Set a custom audio role for the player.",
                                             "role");
    parser.setApplicationDescription("Qt MultiMedia Player Example");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(customAudioRoleOption);
    parser.addPositionalArgument("url", "The URL(s) to open.");
    parser.process(app);

    Player player;

//    if (parser.isSet(customAudioRoleOption))
//        player.setCustomAudioRole(parser.value(customAudioRoleOption));

//    if (!parser.positionalArguments().isEmpty() && player.isPlayerAvailable()) {
//        QList<QUrl> urls;
//        for (auto &a: parser.positionalArguments())
//            urls.append(QUrl::fromUserInput(a, QDir::currentPath(), QUrl::AssumeLocalFile));
//        player.addToPlaylist(urls);
//    }

    player.show();
    return app.exec();
}
