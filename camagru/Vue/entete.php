<header class="row page-header bg-info">
	<div class="col-lg-12 col-xs-12 col-sm-12 col-md-12">
        <div style="min-width: 200px" class="col-lg-4 col-xs-4 col-sm-4 col-md-4">
                    <h1  class="text-secondary">Fotooos</h1>
        </div>
        <div class="col-lg-8 col-xs-8 col-sm-8 col-md-8">
					<h2>Faites de super montage..</h2>
		</div>    
		<div class="row">
        <nav>
        	<div class="col-lg-6 col-lg-offset-3">
			        <a id='Accueil' href="/index.php" class="btn btn-default" role="button">Accueil</a>
			        <a href="/montage/montage.php" class="btn btn-default" role="button">Prendre une photo</a>
					<?php
					if (!empty($_SESSION['id'])){
					?>
			        <a id='compte' href="/Vue/compte.php" class="btn btn-default" role="button">Mon compte</a>
			        <a id='insc2' href="/Controleur/deconnexion.php" class="btn btn-default" role="button">Déconnexion</a>
					<?php
					}
					else {
					?>
					<a href="/Vue/Connexion.php" class="btn btn-default" role="button">Connexion</a>
					<a href="/Vue/Inscription.php" class="btn btn-default" role="button">Inscription</a>
						
					<?php
					}
					
					?>
			</div>
		</nav>
</div>
	</div>
</header>                

				
				
				

