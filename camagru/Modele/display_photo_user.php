
	
	<?php
	if (isset($_GET['page']))
		$offset = htmlspecialchars($_GET['page']) * 20 - 20;
	else
		$offset = 0;
	$req = $bdd->prepare('SELECT id FROM images WHERE id_membre = :id ORDER BY id DESC LIMIT 20 OFFSET '.$offset);
	$req->execute(array('id' => $_SESSION["id"]));
	$resultat = $req->fetchAll();

	$req = $bdd->prepare('SELECT MIN(id) AS "min" FROM images WHERE id_membre = :id');
	$req->execute(array('id' => $_SESSION["id"]));
	$min = $req->fetch();
	
	?>
