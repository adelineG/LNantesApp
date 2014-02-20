void exampleBuildXML()
{

	/*<?xml version="1.0" ?>
	<MyApp>
	    <!-- Settings for MyApp -->
	    <Messages>
		<Welcome>Welcome to MyApp</Welcome>
		<Farewell>Thank you for using MyApp</Farewell>
	    </Messages>
	    <Windows>
		<Window name="MainFrame" x="5" y="15" w="400" h="250" />
	    </Windows>
	    <Connection ip="192.168.0.1" timeout="123.456000" />
	</MyApp>
	*/

	TiXmlDocument doc; 

	// <?xml version="1.0" ?>
	TiXmlElement* msg;
 	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );  
	doc.LinkEndChild( decl );  
 
	// <MyApp>
	TiXmlElement * root = new TiXmlElement( "MyApp" );  
	doc.LinkEndChild( root );  

	// <!-- Settings for MyApp -->
	TiXmlComment * comment = new TiXmlComment();
	comment->SetValue(" Settings for MyApp " );  
	root->LinkEndChild( comment );  
 
	// <Messages>
	TiXmlElement * msgs = new TiXmlElement( "Messages" );  
	root->LinkEndChild( msgs );  
 
	// <Welcome>Welcome to MyApp</Welcome>
	msg = new TiXmlElement( "Welcome" );  
	msg->LinkEndChild( new TiXmlText( "Welcome to MyApp" ));  
	msgs->LinkEndChild( msg );  
 
	// <Farewell>Thank you for using MyApp</Farewell>
	msg = new TiXmlElement( "Farewell" );  
	msg->LinkEndChild( new TiXmlText( "Thank you for using MyApp" ));  
	msgs->LinkEndChild( msg );  
 
	// <Windows>
	TiXmlElement * windows = new TiXmlElement( "Windows" );  
	root->LinkEndChild( windows );  

	// <Window name="MainFrame" x="5" y="15" w="400" h="250" />
	TiXmlElement * window;
	window = new TiXmlElement( "Window" );  
	windows->LinkEndChild( window );  
	window->SetAttribute("name", "MainFrame");
	window->SetAttribute("x", 5);
	window->SetAttribute("y", 15);
	window->SetAttribute("w", 400);
	window->SetAttribute("h", 250);

	// <Connection ip="192.168.0.1" timeout="123.456000" />
	TiXmlElement * cxn = new TiXmlElement( "Connection" );  
	root->LinkEndChild( cxn );  
	cxn->SetAttribute("ip", "192.168.0.1");
	cxn->SetDoubleAttribute("timeout", 123.456); // floating point attrib
	
	//std out & save
	dump_to_stdout( &doc );
	doc.SaveFile( "appsettings.xml" ); 
}

void buildXML(List<Batiments> listeBatiments){
	/*<?xml version="1.0" ?>
	<map>
	    <batiment id="">
		<etage num="">
			<acces type="" x="" y="" versEtage="" versBat=""/>
			<couloir xDebut="" yDebut="" xArrivee="" yArrivee=""/>
			<porte nomSalle="" xDebut="" yDebut="" xArrivee="" yArrivee=""/>
			<separateur xDebut="" yDebut="" xArrivee="" yArrivee=""/>
		</etage>
	    </batiment>
	</map>
	*/

	TiXmlDocument doc; 

	// <?xml version="1.0" ?>
	TiXmlElement* msg;
 	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );  
	doc.LinkEndChild( decl );  
 
	// <map>
	TiXmlElement * root = new TiXmlElement( "map" );  
	doc.LinkEndChild( root );

	for(batiment : listeBatiments)
	{

		// <batiment id="">
		TiXmlElement * bat = new TiXmlElement( "batiment" );
		bat->SetAttribute("id", batiment.id);


		for(etage : batiment.listeEtages)
		{

			// <etage num="">
			TiXmlElement * et = new TiXmlElement( "etage" );
			et->SetAttribute("num", etage.num);

			for(acces : etage.listeAcces)
			{
				TiXmlElement * acces = new TiXmlElement( "acces" );
				acces->SetAttribute("type", acces.type);
				acces->SetAttribute("x", acces.x);
				acces->SetAttribute("y", acces.y);
				acces->SetAttribute("versEtage", acces.versEtage);
				acces->SetAttribute("versBat", acces.versBat);
				et->LinkEndChild(acces);
			}
			for(couloir : etage.listeCouloir)
			{
				TiXmlElement * couloir = new TiXmlElement( "couloir" );
				couloir->SetAttribute("xDebut", couloir.xDebut);
				couloir->SetAttribute("yDebut", couloir.yDebut);
				couloir->SetAttribute("xArrivee", couloir.xArrivee);
				couloir->SetAttribute("yArrivee", couloir.yArrivee);
				et->LinkEndChild(couloir);
			}
			for(porte : etage.listePorte)
			{
				TiXmlElement * porte = new TiXmlElement( "porte" );
				porte->SetAttribute("nomSalle", porte.nomSalle);
				porte->SetAttribute("xDebut", porte.xDebut);
				porte->SetAttribute("yDebut", porte.yDebut);
				porte->SetAttribute("xArrivee", porte.xArrivee);
				porte->SetAttribute("yArrivee", porte.yArrivee);
				et->LinkEndChild(porte);
			}
			for(separateur : etage.listeSeparateurs)
			{
				TiXmlElement * separateur = new TiXmlElement( "separateur" );
				separateur->SetAttribute("xDebut", separateur.xDebut);
				separateur->SetAttribute("yDebut", separateur.yDebut);
				separateur->SetAttribute("xArrivee", separateur.xArrivee);
				separateur->SetAttribute("yArrivee", separateur.yArrivee);
				et->LinkEndChild(separateur);
			}

			bat->LinkEndChild(et);

		}

		root->LinkEndChild( bat );

	}  

	//std out & save
	dump_to_stdout( &doc );
	doc.SaveFile( "mapFac.xml" ); 

}
