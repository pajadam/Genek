/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Graphic User Interface
  ********************************************
  */
#include "gui.hpp"

GUI::GUI( FileLogger *logger )
:ui( API::make_center(390, 300), appearance(true,true,true,false,true,false,false )	 )

,genBridges( ui, rectangle(    270, 5, 130, 25), true)
,saveHeightMap( ui, rectangle( 270, 30, 130, 25), true)

,x(ui, rectangle( 5, 5, 190, 25 ))
,y(ui, rectangle( 5, 35, 190, 25 ))
,z(ui, rectangle( 5, 65, 190, 25 ))

,lx(ui, rectangle( 200, 10, 70, 20 ))
,ly(ui, rectangle( 200, 40, 70, 20 ))
,lz(ui, rectangle( 200, 70, 70, 20 ))
,ll(ui, rectangle( 10, 95, 70, 20 ))

,seedl(ui, rectangle( 10, 120, 40, 20 ))
,seedb(ui, rectangle( 50, 118, 142, 20 ))

,bs(ui, rectangle( 5, 150, 190, 25 ))
,bn(ui, rectangle( 5, 180, 190, 25 ))
,bm(ui, rectangle( 5, 210, 190, 25 ))

,bspa(ui, rectangle( 200, 155, 200, 40 ))
,bmin(ui, rectangle( 200, 185, 200, 40 ))
,bmax(ui, rectangle( 200, 215, 200, 40 ))
,bridl(ui, rectangle( 10, 245, 200, 20 ))

,gen(ui, rectangle( 300, 250, 80, 40 ))
,prog(ui, rectangle( 5, 280, 290, 10 ))
,lprog(ui, rectangle( 5, 265, 290, 15 ))
{
    mLogger = logger;
    mLogger->Log( INFO, mPrefix + "Initializing GUI..." );

    ui.caption( TITLE );
    genBridges.caption( GEN_BRIDGE );
    genBridges.check( gs.generateBridges );

    lprog.caption( "Ready!" );

    saveHeightMap.caption( SAVE_HEIGHTMAP );
    saveHeightMap.check( gs.saveHeightMap );

    genBridges.events().checked(
        [&](){
            gs.generateBridges = (bool)genBridges.checked();
        }
    );

    saveHeightMap.events().checked(
        [&](){
            gs.saveHeightMap = (bool)saveHeightMap.checked();
        }
    );

    gen.caption( "GENERATE" );

    gen.events().click(
        [&](){
            prog.unknown( false );
            prog.value( 0 );
            lprog.caption( "Initializing..." );
            gs.seed = std::hash<std::string>()( sSeed );
            mLogger->Log( INFO, mPrefix + "Seed : '" + sSeed + "'" );
            mLogger->Log( INFO, mPrefix + "Seed hash: '" + to_string( gs.seed ) + "'" );
            Genek generator( mLogger );
            prog.value( prog.amount() / 4 );
            lprog.caption( "Generating level..." );
            generator.generateMap( gs );
            prog.value( prog.amount() / 2 );
            lprog.caption( "Saving level to file..." );
            generator.exportMap();
            prog.value( prog.amount() );
            lprog.caption( "Done!" );
        }
    );

    x.vmax( MAX_SIZE );
    y.vmax( MAX_SIZE );
    z.vmax( MAX_HEIGHT );

    x.value( gs.sizeX );
    y.value( gs.sizeY );
    z.value( gs.sizeZ );

    bs.vmax( MAX_SPACING );
    bn.vmax( MIN_MAX_LENGTH );
    bm.vmax( MAX_LENGTH );

    bs.events().value_changed(
        [&](){
            if( bs.value() > 2 )
                gs.bridgeSpacing = bs.value();
            else
            {
                bs.value( 2 );
                gs.bridgeSpacing = bs.value();
            }
            bspa.caption( "Spacing: " + to_string( bs.value() ) );
        }
    );

    bn.events().value_changed(
        [&](){
            if( bn.value() > 2 )
                gs.bridgeMinLength = bn.value();
            else
            {
                bn.value( 2 );
                gs.bridgeMinLength = bn.value();
            }
            bmin.caption( "Min Length: " + to_string( bn.value() ) );
        }
    );

    bm.events().value_changed(
        [&](){
            if( bm.value() > MIN_MAX_LENGTH )
                gs.bridgeMaxLength = bm.value();
            else
            {
                bm.value( MIN_MAX_LENGTH );
                gs.bridgeMaxLength = bm.value();
            }
            bmax.caption( "Max Length: " + to_string( bm.value() ) );
        }
    );

    bs.value( gs.bridgeSpacing );
    bn.value( gs.bridgeMinLength );
    bm.value( gs.bridgeMaxLength );

    bridl.caption( "BRIDGE GENERATOR SETTINGS" );
    bspa.caption( "Spacing: " + to_string( bs.value() ) );
    bmin.caption( "Min Length: " + to_string( bn.value() ) );
    bmax.caption( "Max Length: " + to_string( bm.value() ) );

    x.events().value_changed(
        [&](){
            if( x.value() > MIN_SIZE )
                gs.sizeX = x.value();
            else
            {
                x.value( MIN_SIZE );
                gs.sizeX = x.value();
            }
            lx.caption( "X: " + to_string( gs.sizeX ) );
        }
    );

    y.events().value_changed(
        [&](){
            if( y.value() > MIN_SIZE )
                gs.sizeY = y.value();
            else
            {
                y.value( MIN_SIZE );
                gs.sizeY = y.value();
            }
            ly.caption( "Y: " + to_string( gs.sizeY ) );
        }
    );

    z.events().value_changed(
        [&](){
            if( z.value() > MIN_HEIGHT )
                gs.sizeZ = z.value();
            else
            {
                z.value( MIN_HEIGHT );
                gs.sizeZ = z.value();
            }
            lz.caption( "Z: " + to_string( gs.sizeZ ) );
        }
    );

    lx.caption( "X: " + to_string( gs.sizeX ) );
    ly.caption( "Y: " + to_string( gs.sizeY ) );
    lz.caption( "Z: " + to_string( gs.sizeZ ) );
    ll.caption( "LEVEL SIZE" );

    seedl.caption( "SEED:" );
    seedb.multi_lines( false );
    seedb.tip_string( "LEVEL SEED" );

    seedb.events().text_changed(
        [&](){
            seedb.getline( 0, sSeed );
        }
    );



    paint::image icon("data/icon.ico");

    API::window_icon( ui, icon );
}

GUI::~GUI()
{
    mLogger->Log( INFO, mPrefix + "Destructor." );
}

void GUI::Start()
{
    mLogger->Log( INFO, mPrefix + "Running GUI..." );
    ui.show();
    exec();
}
