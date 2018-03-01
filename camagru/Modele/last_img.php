
	
	<?php
	
	$req = $bdd->prepare('SELECT MAX(id) as "id" FROM images');
	$req->execute();
	$resultat = $req->fetch();
	
	?>