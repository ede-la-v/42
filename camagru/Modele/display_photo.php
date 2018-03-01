
	
	<?php
	if (isset($_GET['page']))
		$offset = htmlspecialchars($_GET['page']) * 20 - 20;
	else
		$offset = 0;
	$req = $bdd->prepare('SELECT id FROM images ORDER BY id DESC LIMIT 20 OFFSET '.$offset);
	$req->execute();
	$resultat = $req->fetchAll();
	
	$req = $bdd->prepare('SELECT MIN(id) AS "min" FROM images');
	$req->execute();
	$min = $req->fetch();
	
	?>
